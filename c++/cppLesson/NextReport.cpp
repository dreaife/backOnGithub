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