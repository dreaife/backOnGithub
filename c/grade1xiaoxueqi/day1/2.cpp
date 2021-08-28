#include <iostream>
using namespace std;
namespace A{
    int a=1000;
    namespace B{
        int a=5;
    }
    void out(){
        std::cout<<"namespace A:"<<a<<std::endl;
    }
}
int a=998;
int main(){
    int a=55;
    cout<<a<<endl;
    cout<<A::a<<endl;
    A::out();
    cout<<A::B::a<<endl;
    cout<<::a<<endl;
    return 0;
}