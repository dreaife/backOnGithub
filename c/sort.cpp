#include<bits/stdc++.h>
using namespace std;
const int maxSize=25;
struct stu{
	int gra;
	string name;
};
typedef struct{
	stu s[maxSize];
	int length;
}sList;
void swap(sList &a,int i,int j){
	int temp=0;
	string tname;
	temp=a.s[i].gra;a.s[i].gra=a.s[j].gra;a.s[j].gra=temp;
	tname=a.s[i].name;a.s[i].name=a.s[j].name;a.s[j].name=tname;
}
void qSort(sList &a,int l,int r){
	if(l>=r) return;
	int mid=(l+r)/2;
	int i=l-1,j=r+1;
	while(i<j){
		do i++; while(a.s[i].gra<a.s[mid].gra);
		do j--; while(a.s[j].gra>a.s[mid].gra);
		if(i<j)
			swap(a,i,j);
	}
	qSort(a,l,j);
	qSort(a,j+1,r);
}
void bSort(sList &a){
	for(int i=0;i<a.length;i++){
		for(int j=1;j<a.length-i;j++){
			if(a.s[j].gra<a.s[j-1].gra)
				swap(a,j,j-1);
		} 
	}
}
void printS(sList &a){
	for(int i=0;i<a.length;i++){
		cout<<a.s[i].name<<'\t';
		cout<<a.s[i].gra<<endl;
	}
}
void EQ(sList &a,sList b){
	a.length=b.length;
	for(int i=0;i<a.length;i++){
		a.s[i].gra=b.s[i].gra;
		a.s[i].name=b.s[i].name;
	}
}
int main(){
	sList stu;
	cin>>stu.length;
	for(int i=0;i<stu.length;i++){
		cin>>stu.s[i].name;
		cin>>stu.s[i].gra;
	}
	printS(stu);
	//bubbleSort
	sList bs;
	EQ(bs,stu);
	bSort(bs);
	printS(bs);
	//quickSort
	cout<<"quickSort"<<endl;
	sList qs;
	EQ(qs,stu);
	qSort(qs,0,qs.length-1);
	printS(qs);
	return 0;
} 
