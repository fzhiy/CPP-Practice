/*** 
 * @Date: 2022-03-05 11:57:18
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-03-05 12:41:56
 */

// 类的成员函数可以调用类中各个属性的成员。而类的对象只能访问类的public属性成员，
// 而不能访问private和protected属性成员。所以，类的对象访问类中private和protected的时候要借助public成员函数，
// 这就是类的接口函数。这种访问机制实现了类的封装。

// 第一: private,public,protected的访问范围:
 
// private: 只能由该类中的函数、其友元函数访问,不能被任何其他访问，该类的对象也不能访问.
// protected: 可以被该类中的函数、子类的函数、以及其友元函数访问,但不能被该类的对象访问
// public: 可以被该类中的函数、子类的函数、其友元函数访问,也可以由该类的对象访问
// 注：友元函数包括两种：设为友元的全局函数，设为友元类中的成员函数

// 第二:类的继承后方法属性变化:

// 使用private继承,父类的所有方法在子类中变为private;
// 使用protected继承,父类的protected和public方法在子类中变为protected,private方法不变;
// 使用public继承,父类中的方法属性不发生改变;

#include <iostream>
using namespace std;

class A{
public:
    A(int x,int y):x(x),y(y){}
    void show(){print();}  //基类成员可以直接调用protected成员
protected:
    void print()
    {cout<<"x point:"<<x<<endl<<"y point:"<<y<<endl;}
private:
    int x;
    int y;
};
class B:public A{
public:
    B(int x,int y,int z):A(x,y),z(z){}
    void output() 
    {print();   //子类成员可以直接调用基类protected成员
    cout<<"z point:"<<z<<endl;}
private:
    int z;
    void another(){print();} //当然，非public成员也能访问基类protected成员
};
int main()
{
    A a(2,3);
    B b(4,5,6);
    //a.print();//不可以，基类对象不能调用自身protected成员
    a.show();//可以，基类对象调用public成员，间接调用protected成员
    //b.print();//不可以，子类对象不能调用基类protected成员
    b.output(); //可以，子类对象调用自身public成员，该成员函数内部调用了基类保护成员print()
    return 0;
}
/**
 * 输出：
 *  x point:2
    y point:3
    x point:4
    y point:5
    z point:6
 * 
 */