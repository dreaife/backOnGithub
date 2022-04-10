#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int a[100010],cnt;
int n,m;
int b;
int lowbit(int x)
{
	return x&-x;
 } 
int qw(int x)
{
	int ans=0;
	while(x)
	{
		ans++;
		x/=2;
		
	}
	return ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b;
		m++;
		while(b)
		{
			a[qw(lowbit(b))]++;
			cnt=max(qw(lowbit(b)),cnt);
			b-=lowbit(b);
		}
	}
	int flag=0;
	for(int i=cnt;i>=0;i--)
	{
		if(a[i]%2==1)
		{
			if(a[i]/2%2==0||(a[i]/2%2==1&&(m-a[i])%2==1))
			{
				flag=1;
				break;
			}
			else
			{
				flag=-1;
				break;
			}
		}
	}
	if(flag==1)
	{
		cout<<"WIN";
	}
	else if(flag==-1)
	{
		cout<<"LOSE";
	}
	else
	{
		cout<<"DRAW";
	} 
	
}
