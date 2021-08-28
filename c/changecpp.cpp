#include <iostream>
using namespace std;

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int i = 5;
	int j = 10;
	cout<<"Before swap: i="<<i<<",j="<<j<<endl;
	swap(i,j); //-----------------------------------------------------¢Ù
	cout<<"After the first swap: i="<<i<<",j="<<j<<endl;
	swap(&i,&j); //-----------------------------------------------------¢Ú
	cout<<"After the second swap: i="<<i<<",j="<<j<<endl;
	return 1;
}
