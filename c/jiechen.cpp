#include<iostream>
using namespace std;

int jc(int i){
	int jie;
	if(i==0) jie=1;
	else jie=i*jc(i-1);
	return jie;
}

int main(){
	int n=10;
	cout<<jc(n)<<endl;
	return 0;
} 
