/*** 
 * @Date: 2022-03-05 12:20:49
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-05 12:35:13
 */

#include <iostream>
 
using namespace std;
 
class Box
{
   double width;
public:
   friend void printWidth( Box box );
   void setWidth( double wid );
};
 
// 成员函数定义
void Box::setWidth( double wid )
{
    width = wid;
}
 
// 请注意：printWidth() 不是任何类的成员函数
void printWidth( Box box )
{
   /* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
   cout << "Width of box : " << box.width <<endl;
}
 
// 程序的主函数
int main( )
{
   Box box;
 
   // 使用成员函数设置宽度
   box.setWidth(10.0);
   
   // 使用友元函数输出宽度
   printWidth( box );
 
   return 0;
}

/**
 * 输出： Width of box : 10
 * 
 友元函数的使用
因为友元函数没有this指针，则参数要有三种情况： 
1）要访问非static成员时，需要对象做参数；
2）要访问static成员或全局变量时，则不需要对象做参数；
3）如果做参数的对象是全局对象，则不需要对象做参数.可以直接调用友元函数，不需要通过对象或指针
 */