#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<map>
 
using namespace std;
 
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
 
class puzzle
{
public:
	int f[8];
	int space;
	int count;
	bool operator<(const puzzle &p)const
	{
		for(int i=0;i<8;i++)
		{
			if(f[i]==p.f[i])continue;
			return f[i]<p.f[i];
		}
		return false;
	}
};
 
bool is(puzzle p)
{
	for(int i=0;i<8;i++)
	{
		if(p.f[i]!=i)return false;
	}
	return true;
}
 
int encode(puzzle p)
{
	int ans=0;
	for(int i=0;i<8;i++)
	{
		ans+=p.f[i];
		ans*=10;
	}
	return ans/10;
}
 
map<int,int>V;
 
void bfs(puzzle p)
{
	queue<puzzle>q;
	V[encode(p)]=1;
	p.count=1;
	q.push(p);
	
	while(!q.empty())
	{
		puzzle u=q.front();q.pop();
		int sx=u.space/4;
		int sy=u.space%4;
		for(int r=0;r<4;r++)
		{
			int tx=sx+dx[r];
			int ty=sy+dy[r];
			if(tx<0||ty<0||tx>=2||ty>=4)continue;
			puzzle v=u;
			swap(v.f[u.space],v.f[tx*4+ty]);
			v.space=tx*4+ty;
			if(V[encode(v)]==0)
			{
				v.count=V[encode(v)]=u.count+1;
				q.push(v);
			}
		}
	}
	return;
}
 
int main()
{
	puzzle ans;
	for(int i=0;i<8;i++)ans.f[i]=i;
	ans.space=0;
	bfs(ans);
	int a[8];
	while(~scanf("%d%d%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7]))
	{
		puzzle in;
		for(int i=0;i<8;i++)
		{
			if(a[i]!=0)in.f[i]=a[i];
			else
			{
				in.f[i]=0;
				in.space=i;
			}
		}
		cout<<V[encode(in)]-1<<endl;
	}
	return 0;
}