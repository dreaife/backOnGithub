#include<iostream>
#include<list>
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
    void output(){
        for(auto i=a.end();i!=a.begin();i--)
            cout<<*i;
    }

};

int main(){
    char a[MAXLEN],b[MAXLEN];
    cin>>a>>b;
    BigInt aa(a),bb(b);
    BigInt resAdd = aa+bb;
    resAdd.output();
    return 0;
}