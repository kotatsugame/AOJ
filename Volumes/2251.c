#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

typedef pair<int,int> PII;

const int MAX=2000;
const int INF=1<<28;

int V;//number of vertex
vector<int> G[MAX];
int match[MAX];
bool used[MAX];

void add_edge(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
	return;
}

bool dfs(int v)
{
	used[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		int u=G[v][i],w=match[u];
		if(w<0||!used[w]&&dfs(w))
		{
			match[v]=u;
			match[u]=v;
			return true;
		}
	}
	return false;
}

int bipartite_matching()
{
	int res=0;
	memset(match,-1,sizeof(match));
	for(int v=0;v<V;v++)
	{
		if(match[v]<0)
		{
			memset(used,0,sizeof(used));
			if(dfs(v))res++;
		}
	}
	return res;
}

int dp[100][100];

int main()
{
	int n,m,l;
	while(cin>>n>>m>>l,n)
	{
		V=2*l;
		rep(i,V)G[i].clear();
		rep(i,n)rep(j,n)dp[i][j]=INF;
		rep(i,n)dp[i][i]=0;
		int u,v,d;
		rep(i,m)
		{
			cin>>u>>v>>d;
			dp[u][v]=d;
			dp[v][u]=d;
		}
		rep(k,n)rep(i,n)rep(j,n)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
		PII p[1000];
		rep(i,l)cin>>p[i].second>>p[i].first;
		sort(p,p+l);
		rep(i,l)
		{
			int t=p[i].first;
			int to=p[i].second;
			
			for(int j=i+1;j<l;j++)
			{
				if(p[j].first>=t+dp[to][p[j].second])
				{
					add_edge(i,l+j);
				}
			}
		}
		cout<<l-bipartite_matching()<<endl;
	}
	return 0;
}
