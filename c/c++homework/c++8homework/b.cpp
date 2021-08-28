#include<iostream>
#include<algorithm>
#include<windows.h>
typedef long long ll;
using namespace std;
int divide(int a,int b){
    if(b==0)
        throw a;
    return a/b;
}
int main(){
    try{
        int k=divide(9,3);
        cout<<"9/3 = "<<k<<endl;
        k=divide(6,0);
        cout<<"6/0 = "<<k<<endl;
        k=divide(8,4);
        cout<<"8/4 = "<<k<<endl;
    }catch(int e){
        cout<<e<<"³ýÊýÎª0£¡"<<endl;
    }
    
    system("pause");
    return 0;
}