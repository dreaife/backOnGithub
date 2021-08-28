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