#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+10; 
int h[N];
map<int,int>mp;
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int j=i-h[i];
		sum += mp[j];

        j=h[i];
		sum += mp[j];
		
		mp[h[i]+i]++;
	}
	cout << sum<<endl;
	return 0;
}
