#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int MAX=10000;
const int INFTY=1<<30;

class edge
{
public:
	int target,cost,len;
	edge(int intarget=0,int incost=0,int inlen=0):
	target(intarget),cost(incost),len(inlen){}
};


int n,col[MAX],d[MAX],l[MAX];
vector<edge> Q[MAX];

int dijkstra(int s)
{
	priority_queue<pair<int,int>> PQ;//weight,id
	for(int i=0;i<n;i++)
	{
		d[i]=l[i]=INFTY;
		col[i]=0;
	}
	d[s]=0;l[s]=0;
	PQ.push(make_pair(0,s));
	col[s]=1;
	pair<int,int> parent[MAX];//vertex,edgenum
	parent[s]=make_pair(-1,0);
	
	while(!PQ.empty())
	{
		pair<int,int> f=PQ.top();PQ.pop();
		int u=f.second;
		col[u]=2;
		if(d[u]<f.first*(-1))continue;
		for(int j=0;j<Q[u].size();j++)
		{
			int v=Q[u][j].target;
			if(col[v]==2)continue;
			if((d[u]+Q[u][j].cost<d[v])||(d[u]+Q[u][j].cost<=d[v]
			&&Q[parent[v].first][parent[v].second].len>Q[u][j].len))
			{
				parent[v]=make_pair(u,j);
				d[v]=d[u]+Q[u][j].cost;
				PQ.push(make_pair(d[v]*(-1),v));
				col[v]=1;
			}
		}
	}
	
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(parent[i].first!=-1)
		{
			ans+=Q[parent[i].first][parent[i].second].len;
		}
	}
	
	return ans;
}

int main()
{
	int m;
	while(cin>>n>>m,n){
	for(int i=0;i<MAX;i++)Q[i].clear();
	int u,v,d,c;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>d>>c;
		u--;v--;
		Q[u].push_back(edge(v,d,c));
		Q[v].push_back(edge(u,d,c));
	}
	
	cout<<dijkstra(0)<<endl;
	}
	return 0;
}