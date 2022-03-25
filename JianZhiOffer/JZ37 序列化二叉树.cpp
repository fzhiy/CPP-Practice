/*** 
 * @Date: 2022-03-25 23:25:40
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-25 23:25:40
 */

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    // 前序遍历 序列化
    char* Serialize(TreeNode *root) {    
        if (!root) return "#";
        string res = to_string(root->val);
        res.push_back(',');
        char* left = Serialize(root->left);
        char* right = Serialize(root->right);
        char* ret = new char[strlen(left) + strlen(right) + res.size()];
        strcpy(ret, res.c_str());
        strcat(ret, left);
        strcat(ret, right);
        return ret;
    }
    TreeNode* deser(char *&s) { // 注意这里是 char *&s, 引用方式
        if (*s == '#') {
            ++ s;
            return nullptr;
        }
        // 构造根节点的值
        int num = 0;
        while (*s != ',') {
            num = num * 10 + (*s - '0');
            ++ s;
        }
        ++ s;
        // 递归构造树
        TreeNode* root = new TreeNode(num);
        root->left = deser(s);
        root->right = deser(s);
        return root;
    }
    TreeNode* Deserialize(char *str) {
        return deser(str);
    }
};