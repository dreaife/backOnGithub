//main.cpp
#include<iostream>
#include"stack.h"

using namespace std;

int main(){
	int n;
	cout<<"��������ת������:"<<endl;
	cin>>n;
    Stack<int> q;
    while(n){
    	q.push(n%2);
    	n=n/2;
	}
	cout<<"�����Ķ�����Ϊ:"<<endl;
	while(!q.isEmpty()){
		int t=q.peek();
		q.pop();
		cout<<t;
	}
    return 0;    
}
