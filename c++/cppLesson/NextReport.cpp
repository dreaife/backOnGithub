#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int cnt(int n,int a){
    if(!n||!a) return 1;
    int t1 = n,t2 = a;
    for(int i=1;i<a;i++)
        t1 *= n-i,t2 *= a-i;
    return t1/t2;
}
void solve(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<cnt(i-1,j-1)<<' ';
        }cout<<endl;
    }
}
int main(){
    solve(8);
    ifstream infile("NextReport.cpp",ios::binary);
    char ch;
    while(infile.peek()!=EOF){
        infile.read(&ch,sizeof(ch));
        cout<<ch;
    }cout<<endl;
    infile.close();
    return 0;
}