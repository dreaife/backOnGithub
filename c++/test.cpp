#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int &f(int b){
    static int a = 1+ b;
    return a;
}
int main(){
    cout<<f(1)<<endl;
    cout<<f(f(1))<<endl;
    return 0;
}