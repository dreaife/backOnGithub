#include <stdio.h>
int main()
{
	void inv(int x[],int n);
	int a[4]={1,4,7,3} , *p=&a[0] ,i;
	for (i=0;i<4;i++) printf("%d\n",*p++);
	printf("\n");
	inv(a ,4);	
	p=a;		//p¸´Ô­ 
	for (i=0;i<4;i++) printf("%d\n",*p++);
	return 0;
}

void inv(int x[],int n)
{
	int i,j,temp,m=(n-1)/2;
	
	for (i=0;i<=m;i++){j=n-1-i;
		temp=x[i],x[i]=x[j],x[j]=temp;}
	return ;
}
