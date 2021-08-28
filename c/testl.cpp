#include<iostream>
using namespace std;
long long int shuMax(long long int a,long long int b);
class fra{
    public:
    long long int up,down;
    void add(fra &B){
    	long long int k=0;
        if(up==0||down==0){
            up=B.up;down=B.down;
        }
        else{
            up=up*B.down+B.up*down;
            down=down*B.down;
            k=shuMax(up,down);
            up=up/k;
            down=down/k;
        }
    }
    void printFra(){
        cout<<up<<'/'<<down<<endl;
    }
};
long long int shuMax(long long int a,long long int b){
	long long int zhi=1;
	for(long long int i=1;i<=min(a,b);i++) if(a%i==0&&b%i==0) zhi=i;
	return zhi;
}
long long int Fs(long long int n){
    long long int fs=0;
    if(n==1||n==2) return 1;
    else{
        fs=Fs(n-1)+Fs(n-2);
        return fs;
    }
}
void newFs(int n,fra &A){
    A.up=1;
    A.down=Fs(n)*Fs(n+1);
}
int main(){
    fra M,N;
    M.up=0;M.down=0;
    for(int i=1;i<=13;i++){
        newFs(i,N);
        M.add(N);
    }
    M.printFra();
    return 0;
}
