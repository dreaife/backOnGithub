#include<iostream>
#include<algorithm>
using namespace std;
int cnt;
void bubbleSort(int arr[],int x){
	for(int i=0;i<x;i++)
		for(int j=i+1;j<x;j++)
			if(arr[i]>arr[j]) swap(arr[i],arr[j]),cnt++;
}
int main()
{
	int *a = new int[10]();cnt=0;
	cout<<"输入a数组"<<endl;
	for(int i=0;i<10;i++) cin>>a[i];
	bubbleSort(a,10);
	cout<<"a数组排序后结果:"<<endl;
	for(int i=0;i<10;i++) cout<<a[i]<<' ';cout<<endl;
	cout<<"冒泡排序交换次数:"<<cnt<<endl;
	return 0;
}