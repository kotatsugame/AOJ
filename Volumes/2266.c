#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int MAX=10100;
const int INF=1<<25;

class edge
{
public:
	int to,cap,cost,rev;
	edge(){}
	edge(int to,int cap,int cost,int rev):to(to),cap(cap),cost(cost),rev(rev){}
};

int V;
vector<edge> G[MAX];
int dist[MAX];
int prevv[MAX],preve[MAX];

void add_edge(int from,int to,int cap,int cost)
{
	G[from].push_back(edge(to,cap,cost,G[to].size()));
	G[to].push_back(edge(from,0,-cost,G[from].size()-1));
	return;
}

int mincostflow(int s,int t,int f)
{
	int res=0;
	while(f>0)
	{
		fill(dist,dist+V,INF);
		dist[s]=0;
		bool update=true;
		while(update)
		{
			update=false;
			for(int v=0;v<V;v++)
			{
				if(dist[v]==INF)continue;
				for(int i=0;i<G[v].size();i++)
				{
					edge &e=G[v][i];
					if(e.cap>0&&dist[e.to]>dist[v]+e.cost)
					{
						dist[e.to]=dist[v]+e.cost;
						prevv[e.to]=v;
						preve[e.to]=i;
						update=true;
					}
				}
			}
		}
		
		if(dist[t]==INF)return -1;
		
		int d=f;
		for(int v=t;v!=s;v=prevv[v])d=min(d,G[prevv[v]][preve[v]].cap);
		f-=d;
		res+=d*dist[t];
		
		for(int v=t;v!=s;v=prevv[v])
		{
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}

int main()
{
	int m,n,k;
	cin>>m>>n>>k;
	V=k+1;
	int w[MAX];
	for(int i=0;i<n;i++)cin>>w[i];
	int prev[MAX];
	memset(prev,-1,sizeof(prev));
	int ans=0;
	for(int i=0;i<k;i++)
	{
		int a;
		cin>>a;
		a--;
		
		add_edge(i,i+1,INF,0);
		
		ans+=w[a];
		
		if(prev[a]!=-1)
		{
			if(prev[a]+1==i)
			{
				ans-=w[a];
			}
			else
			{
				add_edge(prev[a]+1,i,1,-w[a]);
			}
		}
		
		prev[a]=i;
	}
	
	cout<<ans+mincostflow(0,k,m-1)<<endl;
	return 0;
}