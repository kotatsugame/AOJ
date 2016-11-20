#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<queue>

using namespace std;

const int N=3;
const int N2=9;

class puzzle
{
public:
	int f[N2];
	int space;
	string path;
	
	bool operator<(const puzzle &p)const
	{
		for(int i=0;i<N2;i++)
		{
			if(f[i]==p.f[i])continue;
			return f[i]>p.f[i];
		}
		return false;
	}
};

const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
const char dir[4]={'u','l','d','r'};

bool istarget(puzzle p)
{
	for(int i=0;i<N2;i++)if(p.f[i]!=i+1)return false;
	return true;
}

string bfs(puzzle s)
{
	queue<puzzle>Q;
	map<puzzle,bool>V;
	puzzle u,v;
	s.path="";
	Q.push(s);
	V[s]=true;
	
	while(!Q.empty())
	{
		u=Q.front();Q.pop();
		if(istarget(u))return u.path;
		int sx=u.space/N;
		int sy=u.space%N;
		for(int r=0;r<4;r++)
		{
			int tx=sx+dx[r];
			int ty=sy+dy[r];
			if(tx<0||tx>=N||ty<0||ty>=N)continue;
			v=u;
			swap(v.f[u.space],v.f[tx*N+ty]);
			v.space=tx*N+ty;
			if(!V[v])
			{
				V[v]=true;
				v.path+=dir[r];
				Q.push(v);
			}
		}
	}
	
	return "unsolvable";
}

int main()
{
	puzzle in;
	for(int i=0;i<N2;i++)
	{
		cin>>in.f[i];
		if(in.f[i]==0)
		{
			in.f[i]=N2;
			in.space=i;
		}
	}
	
	string ans=bfs(in);
	
	if(ans!="unsolvable")cout<<ans.length()<<endl;
	else cout<<ans<<endl;
	
	return 0;
}