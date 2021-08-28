#include <stdio.h>
int main(){
	int a=0,b=0,c=0,max=0;
	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);
	printf("c=");
	scanf("%d",&c);
	if (a>b){
		max=a;
		if (a>c) max=a;
		else max=c;
	}
	else{
		if (b>c)max=b;
		else max=c;
	}
	printf("%d",max);
	return 0;
}

