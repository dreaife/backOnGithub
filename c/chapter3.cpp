#include <stdio.h>
int main()
{
	float f,c;
	//#define a 10				//无分号; 
	f=56.0;
	
	unsigned int a=1;
	c=(5.0/9)*(f-32);
	printf("%f \101 %f\n",c,f);//浮点数%f 
	printf("abc=%u\n",a);		   //unsigned 数用%u
	
	//字符变量%c
	char m='a';
	printf("%d\n%c",m,m); 
	return 0;
}
