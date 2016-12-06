#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

const int MAX=200;

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

int main()
{
	int E,X,Y;cin>>X>>Y>>E;
	V=X+Y;
	int u,v;
	for(int i=0;i<E;i++)
	{
		cin>>u>>v;
		v+=X;
		add_edge(u,v);
	}
	cout<<bipartite_matching()<<endl;
	return 0;
}