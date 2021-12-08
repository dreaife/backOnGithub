# <center>实验七 多态性</center>

# 一、实验目的

1. 掌握运算符重载的方法。

2. 掌握使用虚函数的继承实现动态多态性。

3. 掌握纯虚函数及抽象类的使用。


# 二、实验内容

### 1. 设计复数类Complex（请参照教材例题8-1的设计），实现运算符重载

要求：

1. 重载运算符“+”和“*”，使之分别能用于复数相加和相乘。

2. 重载运算符“<<”，使得复数对象能够使用“<<”运算符输出。

```
class Complex{
    public:
        Complex (int,int);                          //构造函数
        Complex (const Complex &c);                 //复制构造函数 
        ~ Complex ();                               //析构函数
        
        Complex operator + (Complex &m);            //重载 + 运算符
        Complex operator * (Complex &m);            //重载 * 运算符
        friend ostream &operator << (ostream &out,
                              const Complex &m);    //重载"<<"运算符 
        int getReal() const {return real;}              //得到复数实部
        int getImag() const {return imag;}              //得到复数虚部
    private:
        int real,imag;                              //复数的实部与虚部
};

int main(void){
    Complex c1(5,4),c3(3,10),c3;                    //定义复数类的对象
     c3 = c1 + c2;
     
     cout << “c3 = “ << c3;
     Complex c4 = c1 * c2 ;
     Cout << “c4 = “ << c4;
    
    return 0;
｝
```

### 2. 定义抽象类Geometry;在此基础上派生出类Rectangle和Circle

定义抽象类Geometry;在此基础上派生出类Rectangle和Circle。二者都有计算对象周长函数double getPerim（） 计算面积的函数double 两者对象的周长和面积，测试动态多态性。

可以用如下代码测试所建立的类是否正确。

```
int main(){
    Rectangle x1(2,3);
     cout<<"Rectangle:"<<endl;
     fun(&x1);

     Circle y1(5);
     cout<<"Circle:"<<endl;
     fun(&y1);
    
    return 0;
}
```

# 三、实验步骤及结果

## 3.1 运算符重载

1. 解题思路

定义一个复数类，实现对复数运算的模拟，完成实验要求。

2. 解题代码

```
#include<iostream>
using namespace std;

class Complex{
    public:
		Complex ();
        Complex (int,int);                          //构造函数
        Complex (const Complex &c);                 //复制构造函数 
        ~ Complex ();                               //析构函数
        
        Complex operator + (Complex &m);            //重载 + 运算符
        Complex operator * (Complex &m);            //重载 * 运算符
        friend ostream &operator << (ostream &out,
                              const Complex &m);    //重载"<<"运算符 
        int getReal() const {return real;}              //得到复数实部
        int getImag() const {return imag;}              //得到复数虚部
    private:
        int real,imag;                              //复数的实部与虚部
};

Complex::Complex():real(0),imag(0){}
Complex::Complex(int a,int b):real(a),imag(b){}
Complex::Complex(const Complex &c):real(c.getReal()),imag(c.getImag()){}
Complex::~Complex(){real = 0;imag = 0;}
Complex Complex::operator + (Complex &m){
	return Complex(real+m.getReal(),imag+m.getImag());
}
Complex Complex::operator * (Complex &m){
	return Complex(real*m.getReal()-imag*m.getImag(),real*m.getImag()+imag*m.getReal());
}
ostream &operator << (ostream &out,const Complex &m){
	return out<<"("<<m.getReal()<<","<<m.getImag()<<")"<<endl;
}
int main(void){
    Complex c1(5,4),c2(3,10),c3;                    //定义复数类的对象
     c3 = c1 + c2;
     
     cout << "c3 = " << c3;
     Complex c4 = c1 * c2 ;
     cout << "c4 = " << c4;
    
    return 0;
}
```

3. 运行截图

![图片描述](https://dn-simplecloud.shiyanlou.com/courses/uid1644676-20211207-1638811406067)


## 3.2 类的派生

1. 解题思路

学生类派生研究生类，完成实验要求。

2. 解题代码

```
#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;
class Student{
    public:
        Student(string a,string b,string c,string d):num(a),name(b),gender(c),major(d){}
        Student(Student &a):num(a.num),name(a.name),gender(a.gender),major(a.major){}
        void display(){
            cout<<"学号:"<<num<<"\t姓名:"<<name<<"\t性别:"<<gender<<"\t专业:"<<major<<endl;
        }
    private:
        string num,name,major,gender;
};
class PostGraduate:public Student{
    public:
        PostGraduate(string a,string b,string c,string d,string e,string f,string g):Student(a,b,c,d),tutor(e),allowance(f),research(g){}
        PostGraduate(Student A,string e,string f,string g):Student(A),tutor(e),allowance(f),research(g){}
        void display(){
            Student::display();
            cout<<"导师:"<<tutor<<"\t津贴:"<<allowance<<"\t研究方向:"<<research<<endl;
        }
    private:
        string tutor,allowance,research;
};
int main(){
    Student s1("20190001", "Michael","Male", "Computer Science");
    cout<<"Student Class:"<<endl;
    s1.display();
    cout<<endl;
    PostGraduate p1(s1,"Liu","1000","Deep learning");
    cout<<"PostGraduate Class:"<<endl;
    p1.display();
    system("pause");
    return 0;
}
```

3. 运行截图

![图片描述](https://dn-simplecloud.shiyanlou.com/courses/uid1644676-20211206-1638778851073)


## 3.3 基类与派生类的指针调用

1. 解题思路

通过基类与派生类的指针调用，完成实验要求。

2. 解题代码

```
#include<iostream>
#include<windows.h>
using namespace std;
class BaseClass{
    public:
        void fn1(){
            cout<<"BaseClass fn1()"<<endl;
        }
        void fn2(){
            cout<<"BaseClass fn2()"<<endl;
        }
    private:
        int i;
};
class DerivedClass:public BaseClass{
    public:
        void fn1(){
            cout<<"DerivedClass fn1()"<<endl;
        }
    private:
        int j;
};
int main(){
    BaseClass* bc1;
    DerivedClass* dc1;
    cout<<"BaseClass指针使用fn1和fn2"<<endl;
    bc1->fn1();
    bc1->fn2();
    cout<<"\n"<<"DerivedClass指针使用fn1和fn2"<<endl;
    dc1->fn1();
    dc1->fn2();
    system("pause");
    return 0;
}
```

3. 运行截图


![图片描述](https://dn-simplecloud.shiyanlou.com/courses/uid1644676-20211206-1638779022836)


4. 实验结果分析

BaseClass的指针可以正常使用BaseClass类的fn1、fn2函数；DerivedClass的指针可以正常使用DerivedClass的fn1函数，对于其未定义的fn2函数，由于类型兼容规则调用了基类的fn2函数。

## 3.4 基类与派生类的构造函数和析构函数的调用顺序


1. 解题思路

让每个类及其派生类输出当前类的名字，再定义一个最终的派生类，初始化，观察输出结果。

2. 解题代码

```
#include<iostream>
#include<algorithm>
using namespace std;
class Document{
	public:
		Document(){
			cout<<"Create Document"<<endl;
			name = 0;
		}
		~Document(){
			cout<<"Delete Document"<<endl;
		}
		int name;
};
class Book:public Document{
	public:
		Book(){
			cout<<"Create Book\n";
			pageCount = 0;
		}
		~Book(){
			cout<<"Delete Book\n";
		}
		int pageCount;
};
int main(){
	Book b1;
	return 0;
}
```

3. 运行截图


![图片描述](https://dn-simplecloud.shiyanlou.com/courses/uid1644676-20211206-1638780462867)


## 3.5 组合与继承有什么共同点和差异、通过组合/继承生成的类与被组合的类之间的逻辑关系是什么
- 思路

> 1. 组合和继承的共同点
> 
> 继承和组合的使用都可以减少重复代码，同时若类B是类A的内嵌对象，则B类具有A类的全部数据。

> 2. 组合和继承的不同点
> 
> 组合是通过在其他类中定义对象来使用类中的方法和属性，不能访问父类的任何接口。而继承则是从父类中得到方法和属性，即可以得到父类的全部接口，并加以调用。

> 3. 通过组合生成的类和被组合的类之间的逻辑关系
> 
> 组合生成的类具有被组合类的全部内容，但是并不包括被组合类的全部接口，就是通过被组合的类的对象只能访问组合类的成员函数，但不能直接访问到被组合类的成员函数。

> 4. 继承类与基类的逻辑关系
> 
> 即通过派生类的对象不但可以访问派生类的成员函数，也能访问基类的成员函数，派生类是可以完全继承基类的任何内容的包括全部接口。


# 四、实验小结

## 4.1 实验中的问题

> - **问题**
> 
> 对派生类继承父类的数据修改时失败

> - **解决方案**
> 
> 父类数据访问类型未设置成public，将其修改为public后成功

## 4.2 心得与体会

本次实验报告完成了关于类在c++中类的继承与派生的定义及其功能实现。通过这次实验，我掌握类的公有继承、私有继承跟保护继承的定义及用法，并能通过对象调用基类及派生类的成员函数，完成简单的程序设计，进一步掌握用类和对象编制基于对象的程序。