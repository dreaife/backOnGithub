#include <stdio.h>
int main()
{
	void swap(int *p1 ,int *p2);
	int a,b,c;
	int *p_a=&a,*p_b=&b,*p_c=&c;
	scanf("%d%d%d",&a,&b,&c);
	if (a<=b) swap(p_a,p_b);
	if (a<=c) swap(p_a,p_c);
	if (b<=c) swap(p_b,p_c);
	
	
	printf("%d	%d	%d",*p_a,*p_b,*p_c);
	return 0;
 } 
 
void swap(int *p1 ,int *p2)
{
	int p;
	p=*p1;
	*p1=*p2;
	*p2=p;	
}
