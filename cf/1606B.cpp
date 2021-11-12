#include<iostream>
#include<list>
#include<cstring>
using namespace std;
const int MAXLEN = 1e5+10;

int get(list<int> t,int p){int i=0;
    for(auto it = t.begin();;i++,it++) if(i==p)
        return *it;
    return 0;
}

struct BigInt{
    const static int mod = 10000;
    const static int DLEN = 4;
    const static int MAXN = 9999;
    list<int> a;
    int len;
    BigInt(){
        a.clear();
        len = 1;
    }
    BigInt(const char s[]){
        a.clear();
        int L = strlen(s);
        len = L/DLEN;
        if (L%DLEN) len++;
        int index = 0;
        for(int i=L-1;i>=0;i -= DLEN){
            int t = 0;
            int k=i-DLEN+1;
            if(k<0) k = 0;
            for(int j=k;j<=i;j++) t = t*10+s[j]-'0';
            a.push_back(t);index++;
        }
    }
    BigInt operator +(const BigInt &b)const{
        BigInt res;
        res.len = max(len,b.len);
        res.a.clear();auto it = res.a.begin();
        for(int i=0;i<res.len;i++,it++){
            res.a.push_back(0);
            *it += ((i<len)?get(a,i):0)+((i<b.len)?get(b.a,i):0);
            *(++it) += *it/mod;
            *(--it) %= mod;
        }
        return res;
    }
    bool operator >(const BigInt &b)const{
        auto ln1 = a.end(),ln2=b.a.end();
        if(len>b.len) return true;
        else if(len == b.len){
            while(*ln1 == *ln2 && ln1!=a.begin())
                ln1--,ln2--;
            if(ln1!=a.begin() && *ln1>*ln2)
                return true;
            else return false;
        }else return false;
    }
    BigInt operator -(const BigInt &b)const{
        int i,j,big;
        BigInt t1,t2;
        bool flag;
        if(*this>b){
            t1 = *this;
            t2=b;
            flag=0;
        }
        else {
            t1=b;
            t2=*this;
            flag =1;
        }
        big = t1.len;i=0;
        auto j1=t1.a.begin(),j2=t2.a.begin();
        auto i1=t1.a.begin(),i2=t2.a.begin();
        for(;i<big;i++,i1++,i2++){
            if(*i1<*i2){
                j1=++i1;i1--;j=i+1;
                while(*j1==0) j++,j1++;
                *(j1--)--;j--;
                while(j>i) *(j1--)+=MAXN,j--;
                *i1+=MAXN+1-*i2;
            }
            else *i1-=*i2;
        }t1.len=big;
        while(*(--i1)==0 && t1.len>1){
            t1.len--;
            big--;
        }*i1++;
        if(flag) *i1=0-*i1;
        return t1;
    }
    void output(){
        for(auto i=a.end();i!=a.begin();i--){
            if(i!=++a.begin()) cout<<*i;
            else cout<<*i-1;
        }
        cout<<endl;
    }

};

int main(){
    char a[MAXLEN],b[MAXLEN];
    cin>>a>>b;
    BigInt aa(a),bb(b);
    BigInt resAdd = aa+bb,resDiv = aa-bb;
    resAdd.output();
    resDiv.output();
    return 0;
}