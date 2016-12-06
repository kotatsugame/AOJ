#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int dp[1010][1010]={};
	int n,m;cin>>n>>m;
	int d[1010];
	int c[1010];
	for(int i=0;i<n;i++)cin>>d[i];
	for(int i=0;i<m;i++)cin>>c[i];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)dp[i][j]=1<<28;
	for(int i=0;i<=m;i++)dp[n][i]=0;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=m;j>=0;j--)
		{
			if(j+1<=m)dp[i][j]=min(dp[i][j+1],dp[i+1][j+1]+d[i]*c[j]);
			else if(i!=n)dp[i][j]=1<<28;
		}
	}
	cout<<dp[0][0]<<endl;
	return 0;
}