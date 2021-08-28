#include<iostream>
#include<windows.h>
#include<vector>
using namespace std;
void putin(int *L){
    for(int i=0;i<5;i++)
        cin>>L[i];
}
void Ascending(int *L,int n){
    int temp=0;
    int index=0;
    for(int i=0;i<n;i++){
        index=i;
        for(int j=i+1;j<n;j++)
            if(L[j]<L[index]) index=j;
        if(L[i]>L[index]){
            temp=L[i];
            L[i]=L[index];
            L[index]=temp;
        }
    }
}
void MergeList(int *L,int* L1,int* L2,int n){
    for(int i=0;i<5;i++) L[i]=L1[i];
    for(int i=5;i<n;i++) L[i]=L2[i-5];
    Ascending(L,n);
}
int main(){
    int *La=new int[5];
    int *Lb=new int[5];
    int *Lc=new int[10];
    putin(La);
    putin(Lb);
    Ascending(La,5);
    Ascending(Lb,5);
    MergeList(Lc,La,Lb,10);
    for(int i=0;i<10;i++) cout<<Lc[i];
    cout<<endl;
    system("pause");
    return 0;
}