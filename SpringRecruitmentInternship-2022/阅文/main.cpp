/*** 
 * @Date: 2022-04-08 10:21:47
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-04-08 15:54:01
 */

#include <iostream>

class ScopedPtr {
public:
    ScopedPtr(int* x) : _x(x) {
    }
    ScopedPtr() {}
    ~ScopedPtr() {delete _x;}
    // 解引用运算符 重载, 返回值必须是 引用，因为下面的 *ptr是左值
    int& operator * () {
        return *_x;
    }
    // *= 运算符重载
    int operator *= (int n) {
        return (*_x) * n;
    }
private:
    int* _x;
};

void test(int n) {
    ScopedPtr ptr(new int(n));

    *ptr *= 2;

    std::cout << *ptr << std::endl;
}

int main () {
    int n = 0;
    std::cin >> n;

    test(n);

    return 0;
}
