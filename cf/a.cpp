#include<iostream>
#include<algorithm>
#include<cstring>
#include<unordered_map>
using namespace std;
unordered_map<int,int> b;
const int N = 110;
int n,k,x;
struct T{
    string name;
    int n,k;
};T a[N];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        b.clear();
        cin>>a[i].name>>k;a[i].n=k;
        for(int i=0;i<k;i++){
            int t;cin>>t;
            b[t]++;
        }a[i].k = b.size();
    }sort(a,a+n,[](T t1,T t2){
        if(t1.k<t2.k) return true;
        else if(t1.k == t2.k)
            if(t1.n < t2.n) return true;
        return false;
    });
    for(int i=0;i<n;i++) cout<<a[i].name<<' ';
    if(n<3){
        for(int i=0;i<3-n;i++) cout<<'- ';
    }
    return 0;
}