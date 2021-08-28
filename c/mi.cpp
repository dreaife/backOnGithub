//main.cpp
#include<iostream>
#include"stack.h"

using namespace std;

int main(){
	int n;
	cout<<"请输入想转换的数:"<<endl;
	cin>>n;
    Stack<int> q;
    while(n){
    	q.push(n%2);
    	n=n/2;
	}
	cout<<"该数的二进制为:"<<endl;
	while(!q.isEmpty()){
		int t=q.peek();
		q.pop();
		cout<<t;
	}
    return 0;    
}
