/*** 
 * @Date: 2022-02-23 15:52:25
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-11 12:52:07
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <mutex>
#include <fstream>

#define STORE_FILE "store/dumpFile"

std::mutex mtx;     // mutex for critical section
std::string delimiter = ":";

// class template to implement Node
template<typename K, typename V> 
class Node {
public:
    int node_level;

    Node() {}

    Node(K k, V v, int);

    ~Node();

    K get_key() const;
    
    V get_value() const;

    void set_value(V);

    // Linear array to hold pointers to next node of different level
    Node<K, V> **forward;

private:
    K key;
    V value;
};

template<typename K, typename V>
Node<K, V>::Node(const K k, const V v, int level) {
    this->key = k;
    this->value = v;
    this->node_level = level;

    // level + 1, because array index is [0, level]
    this->forward = new Node<K, V>*[level+1];

    // Fill forward array with 0(NULL)
    memset(this->forward, 0, sizeof(Node<K, V>*) * (level+1));
};

template<typename K, typename V>
Node<K, V>::~Node() {
    delete []forward;
};

template<typename K, typename V>
K Node<K, V>::get_key() const {
    return key;
}

template<typename K, typename V>
V Node<K, V>::get_value() const {
    return value;
}

template<typename K, typename V>
void Node<K, V>::set_value(V value) {
    this->value = value;
}

// Class template for skiplist
template<typename K, typename V>
class SkipList {
public:
    SkipList(int);

    ~SkipList();

    int get_random_level();

    Node<K, V>* create_node(K, V, int);

    int insert_element(K, V);

    void display_list();

    bool search_element(K);

    void delete_element(K);

    void dump_file();

    void load_file();

    int size();

private:
    
    // Maximum level of the skip list 
    int _max_level;
    
    // current level of skip list
    int _skip_list_level;

    // pointer to header node
    Node<K, V> *_header;

    // file operator
    std::ofstream _file_writer;
    std::ifstream _file_reader;

    // skiplist current element count
    int _element_count;

    void get_key_value_from_string(const std::string& str, std::string* key, std::string* value);

    bool is_valid_string(const std::string& str);
};


// create new node 
template<typename K, typename V>
Node<K, V>* SkipList<K, V>::create_node(const K k, const V v, int level) {

    Node<K, V> *n = new Node<K, V>(k, v, level);
    return n;
}

/**Insert given key and value in skip list
 *  return 1 means element exists
 *  return 0 means insert operation sucessfully.
 * /
/**
 * `------>` is the process of the insert operation. 
 *              +-----------+
 *              | insert 50 |
 *              +-----------+
 * level 4      +-->1+                                                          100
 *                   |
 *                   |                        insert +----+
 * level 3          1+--------->10+----------------> | 50 |         70          100
 *                                                   |    |
 *                                                   |    | 
 * level 2          1           10      30           | 50 |         70          100
 *                                                   |    |
 *                                                   |    |
 * level 1          1     4     10      30           | 50 |         70          100
 *                                                   |    |
 *                                                   |    |
 * level 0          1     4  9  10      30     40    | 50 |         70          100
 *                                                   +----+
 */

template<typename K, typename V>
int SkipList<K, V>::insert_element(const K key, const V value) {

    mtx.lock();     // lock before inserting
    Node<K, V> *current = this->_header;    // head node

    // create update array and initialize it 
    // update is array which put node that the node->forward[i] should be opearated later
    Node<K, V> *update[_max_level+1];
    memset(update, 0, sizeof(Node<K, V>*) * (_max_level+1));

    // start from highest level of skip list
    for (int i = _skip_list_level; i >= 0; i --) {
        while (current->forward[i] != NULL && current->forward[i]->get_key() < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    // reached level 0 and forward pointer to right node, which is desired to insert key.
    current = current->forward[0];
    if (current != NULL)
        std::cout << "current->get_key() : " << current->get_key() << std::endl;

    // if current node have key equal to searched key, we get it
    if (current != NULL && current->get_key() == key) {
        std::cout << "key:" << key << ", exist" << std::endl;
        mtx.unlock();
        return 1;
    }

    // if current is NULL that means we have reached to end of the level
    // if current's key is not equal to key that means we have to insert node between update[0] and current node
    if (current == NULL || current->get_key() != key) { //  current->get_key() > key > update[0] 

        // Generate a random level for node
        int random_level = get_random_level();
        std::cout << random_level << " " << _max_level << std::endl;
        // If random level is greater than skiplist's current level, initialize update value with pointer to header
        if (random_level > _skip_list_level) {
            for (int i = _skip_list_level+1; i < random_level+1; i++) {
                update[i] = _header;
            }
            _skip_list_level = random_level;
        }

        // Create new node with random level generated
        Node<K, V>* insert_node = create_node(key, value, random_level);

        // insert node
        for (int i = 0; i <= random_level; i++) {
            insert_node->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = insert_node;
        }

        std::cout << "Successfully inserted key:" << key << ", value:" << value << std::endl;
        _element_count ++;
    }
    mtx.unlock();
    return 0;
}

// Display skiplist
template<typename K, typename V>
void SkipList<K, V>::display_list() {
    
    std::cout << "\n******Skip List******\n";

    for (int i=0; i<=_skip_list_level; i++) {
        Node<K, V> *node = this->_header -> forward[i];
        std::cout << "Level" << i << ": ";

        while (node != NULL) {
            std::cout << node -> get_key() << ":" << node->get_value() << ";";
            node = node -> forward[i];
        }
        std::cout << std::endl;
    }
}

/// Dump data in memory to file
template<typename K, typename V>
void SkipList<K, V>::dump_file() {
    
    std::cout << "dump_file============================" << std::endl;

    _file_writer.open(STORE_FILE);
    Node<K, V> *node = this->_header -> forward[0];

    while (node != NULL) {
        _file_writer << node->get_key() << ":" << node->get_value() << "\n";

        std::cout << node->get_key() << ":" << node->get_value() << ";\n";

        node = node -> forward[0];
    }

    _file_writer.flush();
    _file_writer.close();
    return ;
}

// load data from disk
template<typename K, typename V>
void SkipList<K, V>::load_file() {

    _file_reader.open(STORE_FILE);

    std::cout << "load_file=====================" << std::endl;
    std::string line;
    std::string *key = new std::string();
    std::string *value = new std::string();
    while (getline(_file_reader, line)) {
        get_key_value_from_string(line, key, value);
        if (key->empty() || value->empty()) {
            continue;
        }
        insert_element(*key, *value);
        
        std::cout << "key:" << *key << "value:" << *value << std::endl;
    }
    _file_reader.close();
}

// Get current SkipList size
template<typename K, typename V>
int SkipList<K, V>::size() {
    return _element_count;
}

template<typename K, typename V>
void SkipList<K, V>::get_key_value_from_string(const std::string& str, std::string* key, std::string* value) {

    if (!is_valid_string(str)) {
        return;
    }
    *key = str.substr(0, str.find(delimiter));
    *value = str.substr(str.find(delimiter)+1, str.length());
}

template<typename K, typename V>
bool SkipList<K, V>::is_valid_string(const std::string& str) {

    if (str.empty()) {
        return false;
    }
    if (str.find(delimiter) == std::string::npos) {
        return false;
    }
    return true;
}

// Delete element from skiplist
template<typename K, typename V>
void SkipList<K, V>::delete_element(K key) {

    mtx.lock();
    Node<K, V> *current = this->_header;
    Node<K, V> *update[_max_level+1];
    memset(update, 0, sizeof(Node<K, V>*) * (_max_level + 1));

    // start from highest level of skip list
    for (int i=_skip_list_level; i>=0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->get_key() < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current != NULL && current->get_key() == key) {
        // start for lowest level and delete the current node of each level
        for (int i=0; i<=_skip_list_level; i++) {
            // if at level i, next node is not target node, break the loop.
            if (update[i]->forward[i] != current) {
                break;
            }

            update[i]->forward[i] = current->forward[i];
        }

        // Remove levels which have no elements.
        while (_skip_list_level > 0 && _header->forward[_skip_list_level] == 0) {
            _skip_list_level --;
        }

        std::cout << "Successfully deleted key " << key << std::endl;
        _element_count --;
    }
    mtx.unlock();
    return ;
}

/** Search for element in skiplist
 * @brief 
 *                      +--------------+
 *                      |  select 60   |
 *                      +--------------+
 * level 4  +-->1+                                                          100
 *               |
 *               |
 * level 3      1+---------->10+------------------->50+          70          100
 *                                                    |
 *                                                    |
 * level 2      1            10         30          50|          70          100
 *                                                    |
 *                                                    |
 * level 1      1    4       10         30          50|          70          100
 *                                                    |
 *                                                    |
 * level 0      1    4    9  10         30    40    50+-->60     70          100
 */
template<typename K, typename V>
bool SkipList<K, V>::search_element(K key) {

    std::cout << "search_element=====================" << std::endl;
    Node<K, V> *current = _header;

    // start from highest level of skip list
    for (int i=_skip_list_level; i>=0; i--) {
        while (current->forward[i] && current->forward[i]->get_key() < key) {
            std::cout << "当前节点的key: " << current->forward[i]->get_key() << std::endl;
            current = current->forward[i];
        }
    }

    // reached level 0 and advance pointer to right node, which we search
    current = current->forward[0];

    // if current node have key equal to searched key, we get it
    if (current and current->get_key() == key) {
        std::cout << "Found key: " << key << ", value: " << current->get_value() << std::endl;
        return true;
    }

    std::cout << "Not Found key:" << key << std::endl;
    return false;
}

// Construct skiplist
template<typename K, typename V>
SkipList<K, V>::SkipList(int max_level) {

    this->_max_level = max_level;
    this->_skip_list_level = 0;
    this->_element_count = 0;

    // create header node and initialize key and value to null
    K k;
    V v;
    this->_header = new Node<K, V> (k, v, _max_level);
};

template<typename K, typename V>
SkipList<K, V>::~SkipList() {

    if (_file_writer.is_open()) {
        _file_writer.close();
    }

    if (_file_reader.is_open()) {
        _file_reader.close();
    }
    delete _header;
}

template<typename K, typename V>
int SkipList<K, V>::get_random_level() {

    int k = 1;
    while (rand() % 2) {
        k ++;
    }
    k = (k < _max_level) ? k : _max_level;
    return k;
}
