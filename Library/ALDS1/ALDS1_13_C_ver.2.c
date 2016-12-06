//A*(priority_queue)
//MD=manhattan direction
#include<iostream>
#include<string>
#include<queue>
#include<set>

using namespace std;

const int N=4;
const int N2=16;

const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};

int MDT[N2][N2];

class puzzle
{
public:
	int f[N2];
	int space;
	int MD;
	int cost;
	
	bool operator<(const puzzle &p)const
	{
		for(int i=0;i<N2;i++)
		{
			if(f[i]==p.f[i])continue;
			return f[i]<p.f[i];
		}
		return false;
	}
};

class state
{
public:
	puzzle p;
	int est;//estimated
	bool operator<(const state &s)const
	{
		return est>s.est;
	}
};

int getallMD(puzzle p)
{
	int sum=0;
	for(int i=0;i<N2;i++)
	{
		if(p.f[i]==N2)continue;
		sum+=MDT[i][p.f[i]-1];
	}
	return sum;
}

int encode(puzzle s)
{
	int cur=0,enc=0;
	for(int i=0;i<N2;i++)
	{
		if(s.f[i]==N2)
		{
			s.f[i]=0;
			break;
		}
	}
	for(int i=0;i<N2-1;i++)
	{
		cur=s.f[i];
		for(int j=i+1;j<N2;j++)
		{
			if(cur<s.f[j])s.f[j]--;
		}
		(enc+=s.f[i])*=N2-1-i;
	}
	return enc;
}

int astar(puzzle s)
{
	priority_queue<state>PQ;
	s.MD=getallMD(s);
	s.cost=0;
	set<int>V;
	puzzle u,v;
	state initial;
	initial.p=s;
	initial.est=s.MD;;
	PQ.push(initial);
	
	while(!PQ.empty())
	{
		state st=PQ.top();PQ.pop();
		u=st.p;
		if(u.MD==0)return u.cost;
		V.insert(encode(u));
		int sx=u.space/N;
		int sy=u.space%N;
		
		for(int r=0;r<4;r++)
		{
			int tx=sx+dx[r];
			int ty=sy+dy[r];
			if(tx<0||tx>=N||ty<0||ty>=N)continue;
			v=u;
			v.MD-=MDT[tx*N+ty][v.f[tx*N+ty]-1];
			v.MD+=MDT[sx*N+sy][v.f[tx*N+ty]-1];
			swap(v.f[sx*N+sy],v.f[tx*N+ty]);
			v.space=tx*N+ty;
			if(!V.count(encode(v)))
			{
				v.cost++;
				state news;
				news.p=v;
				news.est=v.cost+v.MD;
				PQ.push(news);
			}
		}
	}
	
	return -1;
}

int main()
{
	for(int i=0;i<N2;i++)
	{
		for(int j=0;j<N2;j++)
		{
			MDT[i][j]=abs(i/N-j/N)+abs(i%N-j%N);
		}
	}
	
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
	
	cout<<astar(in)<<endl;
	
	return 0;
}