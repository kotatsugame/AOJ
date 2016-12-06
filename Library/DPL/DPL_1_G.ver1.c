#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n,W;cin>>n>>W;
	int dp[10001];
	for(int i=0;i<=W;i++)dp[i]=0;
	int v[100],w[100],m[100];
	for(int i=0;i<n;i++)cin>>v[i]>>w[i]>>m[i];
	for(int i=0;i<n;i++)
	{
		int num=m[i];
		for(int k=1;num>0;k<<=1)
		{
			int mul=min(num,k);
			for(int j=W;j>=w[i]*mul;j--)
			{
				dp[j]=max(dp[j],dp[j-w[i]*mul]+v[i]*mul);
			}
			num-=mul;
		}
	}
	cout<<dp[W]<<endl;
	return 0;
}