//IDA*(Iterative Deepening A*)
//MD=manhattan direction
#include<iostream>
#include<string>

using namespace std;

const int N=4;
const int N2=16;
const int LIMIT=45;

const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
const char dir[4]={'u','l','d','r'};

int MDT[N2][N2];

class puzzle
{
public:
	int f[N2];
	int space;
	int MD;
};

puzzle state;
int limit;
int path[LIMIT];

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

bool istarget()
{
	for(int i=0;i<N2;i++)if(state.f[i]!=i+1)return false;
	return true;
}

bool dfs(int depth,int prev)
{
	if(state.MD==0)return true;
	if(depth+state.MD>limit)return false;
	
	int sx=state.space/N;
	int sy=state.space%N;
	puzzle tmp;
	
	for(int r=0;r<4;r++)
	{
		int tx=sx+dx[r];
		int ty=sy+dy[r];
		if(tx<0||tx>=N||ty<0||ty>=N)continue;
		if(abs(prev-r)==2)continue;
		tmp=state;
		state.MD-=MDT[tx*N+ty][state.f[tx*N+ty]-1];
		state.MD+=MDT[sx*N+sy][state.f[tx*N+ty]-1];
		swap(state.f[sx*N+sy],state.f[tx*N+ty]);
		state.space=tx*N+ty;
		if(dfs(depth+1,r)){path[depth]=r;return true;}
		state=tmp;
	}
	
	return false;
}

string IDA(puzzle in)
{
	in.MD=getallMD(in);
	
	for(limit=in.MD;limit<=LIMIT;limit++)
	{
		state=in;
		if(dfs(0,-3))
		{
			string ans="";
			for(int i=0;i<limit;i++)ans+=dir[path[i]];
			return ans;
		}
	}
	return "unsolvable";
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
	
	string ans=IDA(in);
	
	if(ans!="unsolvable")cout<<ans.length()<<endl;
	else cout<<ans<<endl;
	
	return 0;
}