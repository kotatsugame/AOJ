#include <iostream>
using namespace std;

const int INF=1<<30;
int dp[101][10001]={};

int main() {
	int n,W;cin>>n>>W;
	int v[100],w[100];
	for(int i=0;i<n;i++)cin>>v[i]>>w[i];
	int maxv=0;
	for(int i=0;i<n;i++)maxv=max(maxv,v[i]);
	for(int i=1;i<=100*n;i++)dp[0][i]=INF;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=n*maxv;j++)
		{
			if(j<v[i])
			{
				dp[i+1][j]=dp[i][j];
			}
			else
			{
				dp[i+1][j]=min(dp[i][j],dp[i][j-v[i]]+w[i]);
			}
		}
	}
	int res=0;
	for(int i=0;i<=n*maxv;i++)if(dp[n][i]<=W)res=i;
	cout<<res<<endl;
	return 0;
}