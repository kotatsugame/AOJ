#include <iostream>
using namespace std;

int main() {
	int n,W;cin>>n>>W;
	int v[100],w[100];
	for(int i=0;i<n;i++)cin>>v[i]>>w[i];
	int dp[W+1]={};
	for(int i=0;i<n;i++)
	{
		for(int j=w[i];j<=W;j++)
		{
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout<<dp[W]<<endl;
	return 0;
}