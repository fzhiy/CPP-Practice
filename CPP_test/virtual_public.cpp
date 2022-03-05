/*** 
 * @Date: 2022-03-05 12:02:45
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-05 12:06:40
 */

// 虚拟继承格式： class A : virtual public B
#include <iostream>
 
using namespace std;
//基类
 
class D
{
public:
    D(){cout<<"D()"<<endl;}
    ~D(){cout<<"~D()"<<endl;}
protected:
    int d;
};
 
class B:virtual public D
{
public:
    B(){cout<<"B()"<<endl;}
    ~B(){cout<<"~B()"<<endl;}
protected:
    int b;
};
 
class A:virtual public D
{
public:
    A(){cout<<"A()"<<endl;}
    ~A(){cout<<"~A()"<<endl;}
protected:
    int a;
};
 
class C:public B, public A
{
public:
    C(){cout<<"C()"<<endl;}
    ~C(){cout<<"~C()"<<endl;}
protected:
    int c;
};

int main()
{
    cout << "Hello World!" << endl;
    C c;   //D, B, A ,C
    cout<<sizeof(c)<<endl;  // 40 = 8 * 5(上面的继承方式创建了2个D类型对象)
    return 0;
}
/**
 * 输出：
 *  Hello World!
    D()
    B()
    A()
    C()
    40
    ~C()
    ~A()
    ~B()
    ~D()
 * 
 */