#include <stdio.h>
int main()
{
	float f,c;
	//#define a 10				//�޷ֺ�; 
	f=56.0;
	
	unsigned int a=1;
	c=(5.0/9)*(f-32);
	printf("%f \101 %f\n",c,f);//������%f 
	printf("abc=%u\n",a);		   //unsigned ����%u
	
	//�ַ�����%c
	char m='a';
	printf("%d\n%c",m,m); 
	return 0;
}
