#include<iostream>
#include<windows.h>
#include<cstring>
#include<vector>
using namespace std;
void paixu(vector<string> &s){
    string temp;
    for(int i=0;i<s.size();i++){
        int index=i;
        for(int j=i+1;j<s.size();j++)
            if(s[j]<s[i]) index=j;
        if(s[index]<s[i]){
            temp=s[i];
            s[i]=s[index];
            s[index]=temp;
        } 
    }
}
int main(){
    vector<string> ew(5);
    for(int i=0;i<ew.size();i++) getline(cin,ew[i]);
    paixu(ew);
    for(int i=0;i<ew.size();i++) cout<<ew[i]<<" "<<ew[i].size()<<endl;
    system("pause");
    return 0;
}