#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iomanip>

using namespace std;

class edge
{
public:
	int source,target;
	double cost;
	edge(int insource=0,int intarget=0,double incost=0):
	source(insource),target(intarget),cost(incost){}
	bool operator<(const edge &e)const{return cost>e.cost;}
};

class disjointset
{
public:
	vector<int> rank;
	vector<int> p;
	
	void makeset(int x)
	{
		p[x]=x;
		rank[x]=0;
		return;
	}
	disjointset(int s)
	{
		rank.resize(s);
		p.resize(s);
		for(int i=0;i<s;i++)makeset(i);
		return;
	}
	int findset(int x)
	{
		if(x!=p[x])p[x]=findset(p[x]);
		return p[x];
	}
	void link(int x,int y)
	{
		if(rank[x]>rank[y])p[y]=x;
		else
		{
			p[x]=y;
			if(rank[x]==rank[y])rank[y]++;
		}
		return;
	}
	bool same(int x,int y)
	{
		return findset(x)==findset(y);
	}
	void unite(int x,int y)
	{
		link(findset(x),findset(y));
		return;
	}
};

int n;

double kruskal(vector<edge> e)
{
	sort(e.begin(),e.end());
	disjointset d=disjointset(n);
	edge ne;
	double allcost=0.0;
	
	for(int i=0;i<e.size();i++)
	{
		ne=e[i];
		if(!d.same(ne.source,ne.target))
		{
			allcost+=ne.cost;
			d.unite(ne.source,ne.target);
		}
	}
	
	return allcost;
}

double distance(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
	int m;cin>>n>>m;
	double px[10000],py[10000];
	for(int i=0;i<n;i++)
	{
		cin>>px[i]>>py[i];
	}
	vector<edge> e;
	double all=0.0,now;
	int a,b;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		a--;b--;
		now=distance(px[a],py[a],px[b],py[b]);
		e.push_back(edge(a,b,now));
		e.push_back(edge(a,b,now));
		all+=now;
	}
	
	cout<<fixed<<setprecision(3)<<all-kruskal(e)<<endl;
	return 0;
}