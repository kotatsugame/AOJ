#include<iostream>
#include<algorithm>
using namespace std;
const int M=1400;
int main()
{
	int h,w;cin>>h>>w;
	int c[M+1][M+1],dp[M+1][M+1];
	for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)
	{
		cin>>c[i][j];
		dp[i][j]=0;
	}
	for(int i=0;i<=max(h,w);i++)dp[h][i]=dp[i][w]=0;
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(c[i][j])dp[i][j]=0;
			else dp[i][j]=min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]))+1;
		}
	}
	
	cout<<dp[h][w]<<endl;
	return 0;
}