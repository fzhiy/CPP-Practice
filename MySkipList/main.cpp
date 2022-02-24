/*** 
 * @Date: 2022-02-23 15:41:48
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-02-23 20:27:46
 */

#include <iostream>
#include "skiplist.h"
#define FILE_PATH "./store/dumpFile"

int main() {

    // 键值中的key用int型，如果用其他类型，需要自定义比较函数
    SkipList<int, std::string> skipList(6);

    skipList.insert_element(1, "快学");
    skipList.insert_element(3, "Redis");
    skipList.insert_element(7, "完成");
    skipList.insert_element(8, "论文");
    skipList.insert_element(9, "顺利");
    skipList.insert_element(19, "毕业");
    skipList.insert_element(19, "啊哦");

    std::cout << "skipList size:" << skipList.size() << std::endl;

    skipList.dump_file();

    skipList.search_element(9);
    skipList.search_element(18);

    skipList.display_list();
    
    skipList.delete_element(3);
    skipList.delete_element(7);

    std::cout << "skipList size: " << skipList.size() << std::endl;

    skipList.display_list();
}