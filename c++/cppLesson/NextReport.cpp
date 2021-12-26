#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
void qs(int q[],int l,int r){
    if(l>=r) return ;
    int i=l-1,j=r+1,x=q[l+r>>1];
    while(i<j){
        do i++;while(q[i]>x);
        do j--;while(q[j]<x);
        if(i<j)
            swap(q[i],q[j]);
    }
    qs(q,l,j);
    qs(q,j+1,r);
}
int main(){
    int a[10] = {19, 32, 45, 51, 71, 23, 38, 11, 17, 8};
    qs(a,0,9);
    ofstream t1("f3.dat",ios_base::binary|ios_base::out);
    t1.write((char*)a,sizeof(a));
    t1.close();
    return 0;
}