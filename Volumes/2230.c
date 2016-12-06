#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int,int> P;//shortest pass,vertex number

const int MAX=101;
const int INF=1<<28;

class edge
{
public:
	int to,cap,cost,rev;
	edge(){}
	edge(int to,int cap,int cost,int rev):to(to),cap(cap),cost(cost),rev(rev){}
};

int V;
vector<edge> G[MAX];
int h[MAX];
int dist[MAX];
int prevv[MAX],preve[MAX];

void add_edge(int from,int to,int cap,int cost)
{
	G[from].push_back(edge(to,cap,cost,G[to].size()));
	G[to].push_back(edge(from,0,-cost,G[from].size()-1));
	return;
}

const int inf=1<<20;

void add_edge_lowerlimit(int from,int to,int cap,int cost,int limit)
{
	add_edge(from,to,cap-limit,cost);
	add_edge(from,to,limit,cost-inf);
	return;
}

int mincostflow(int s,int t)
{
	int res=0;
	int f=INF;
	fill(h,h+V,INF);
	h[s]=0;
	rep(v,V)rep(i,G[v].size())
	{
		edge e=G[v][i];
		if(e.cap!=0)h[e.to]=min(h[e.to],h[v]+e.cost);
	}
	while(h[t]<0)
	{
		priority_queue<P> Q;
		fill(dist,dist+V,INF);
		dist[s]=0;
		Q.push(P(0,s));
		
		while(!Q.empty())
		{
			P p=Q.top();Q.pop();
			int v=p.second;
			if(dist[v]<p.first*(-1))continue;
			for(int i=0;i<G[v].size();i++)
			{
				edge &e=G[v][i];
				if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to])
				{
					dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
					prevv[e.to]=v;
					preve[e.to]=i;
					Q.push(P(dist[e.to]*(-1),e.to));
				}
			}
		}
		
		if(dist[t]==INF)return -1;
		
		for(int v=0;v<V;v++)h[v]+=dist[v];
		int d=f;
		for(int v=t;v!=s;v=prevv[v])d=min(d,G[prevv[v]][preve[v]].cap);
		f-=d;
		res+=d*h[t];
		
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
	int n,m;
	cin>>n>>m;
	V=n+1;
	int u,v,s;
	vector<P> GG[100];
	rep(i,m)
	{
		cin>>u>>v>>s;
		add_edge_lowerlimit(u,v,INF,-s,1);
		GG[u].pb(mp(v,s));
	}
	int S=0,T=n;
	int d[100]={};
	rep(i,n)
	{
		rep(j,GG[i].size())
		{
			P e=GG[i][j];
			d[e.fi]=max(d[e.fi],d[i]+e.se);
		}
	}
	add_edge(n-1,n,INF,d[n-1]);
	cout<<mincostflow(S,T)+m*inf<<endl;
	return 0;
}
