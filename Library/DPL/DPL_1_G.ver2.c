#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,W;cin>>n>>W;
	int v[100],w[100],m[100];
	for(int i=0;i<n;i++)cin>>v[i]>>w[i]>>m[i];
	int dp[10001]={};
	int deq[10001],deqv[10001];
	
	for(int i=0;i<n;i++)
	{
		for(int a=0;a<w[i];a++)
		{
			int s=0,t=0;
			for(int j=0;j*w[i]+a<=W;j++)
			{
				int val=dp[j*w[i]+a]-j*v[i];
				while(s<t&&deqv[t-1]<=val)t--;
				deq[t]=j;
				deqv[t++]=val;
				dp[j*w[i]+a]=deqv[s]+j*v[i];
				if(deq[s]==j-m[i])s++;
			}
		}
	}
	cout<<dp[W]<<endl;
	return 0;
}