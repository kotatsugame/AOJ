#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
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

class buin
{
public:
	int a,b,c;
	bool d;
};

int main()
{
	int aa,bb,cc;
	while(cin>>aa>>bb>>cc,aa){
	disjointset d=disjointset(aa+bb+cc+2);
	int s=0,t=aa+bb+cc+1;
	buin f[1000];
	int n;cin>>n;
	int dd;
	for(int i=0;i<n;i++)
	{
		cin>>f[i].a>>f[i].b>>f[i].c>>dd;
		if(dd==1)f[i].d=true;
		else f[i].d=false;
	}
	for(int i=0;i<n;i++)
	{
		if(f[i].d)
		{
			d.unite(s,f[i].a);
			d.unite(s,f[i].b);
			d.unite(s,f[i].c);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(!f[i].d)
		{
			if(d.same(s,f[i].a)&&d.same(s,f[i].b))d.unite(t,f[i].c);
			if(d.same(s,f[i].a)&&d.same(s,f[i].c))d.unite(t,f[i].b);
			if(d.same(s,f[i].b)&&d.same(s,f[i].c))d.unite(t,f[i].a);
		}
	}
	for(int i=s+1;i<t;i++)
	{
		if(d.same(s,i))cout<<1<<endl;
		else if(d.same(t,i))cout<<0<<endl;
		else cout<<2<<endl;
	}}
	return 0;
}