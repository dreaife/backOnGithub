#include<iostream>
using namespace std;

int shuMax(int a,int b){
	int zhi=1;
	for(int i=1;i<=min(a,b);i++) if(a%i==0&&b%i==0) zhi=i;
	return zhi;
}

int shuMin(int x,int y){
	int zhi=max(x,y);
	for(int i=max(x,y);i<=x*y;i++) if(i%x==0&&i%y==0){zhi=i;break;}
	return zhi;
}

int main(){
	int n,m;
	cin>>n>>m;
	cout<<shuMax(n,m)<<"\n"<<shuMin(n,m)<<endl;
	return 0;
}
