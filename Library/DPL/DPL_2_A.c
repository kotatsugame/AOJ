#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int INF=1<<25;

int n;
int m[15][15];
int dp[15][1<<15];

int rec(int s,int v)
{
	if(dp[v][s]>=0)return dp[v][s];
	else if(s==(1<<n)-1&&v==0)return dp[v][s]=0;
	
	int res=INF;
	for(int u=0;u<n;u++)
	{
		if(!(s>>u&1)&&m[v][u]!=INF)res=min(res,rec(s|1<<u,u)+m[v][u]);
	}
	return dp[v][s]=res;
}

int main()
{
	int e,s,t,d;cin>>n>>e;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)m[i][j]=INF;
	for(int i=0;i<e;i++)
	{
		cin>>s>>t>>d;
		m[s][t]=d;
	}
	
	memset(dp,-1,sizeof(dp));
	int ans=rec(0,0);
	if(ans!=INF)cout<<rec(0,0)<<endl;
	else cout<<-1<<endl;
	return 0;
}