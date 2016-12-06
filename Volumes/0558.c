#include<iostream>
#include<queue>
using namespace std;

string s[1000];
int h,w,n;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

int bfs(int x,int y,int now)
{
	int d[h][w]={};
	queue<pair<int,int>>Q;
	Q.push(make_pair(8,x*1000+y));
	while(!Q.empty())
	{
		pair<int,int>a=Q.front();Q.pop();
		int tx=a.second/1000,ty=a.second%1000;
		if(s[tx][ty]-'0'==now)
		{
			return a.first/10;
		}
		for(int r=0;r<4;r++)
		{
			if(abs(a.first%10-r)==2)continue;
			int sx=tx+dx[r];
			int sy=ty+dy[r];
			if(sx<0||sy<0||sx>=h||sy>=w||s[sx][sy]=='X'||d[sx][sy]!=0)continue;
			Q.push(make_pair((a.first/10+1)*10+r,sx*1000+sy));
			d[sx][sy]=1;
		}
	}
	return 1<<26;
}

int main()
{
	cin>>h>>w>>n;
	for(int i=0;i<h;i++)cin>>s[i];
	int c=0;
	pair<int,int> pr[9];
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(s[i][j]=='S')
			{
				pr[0]=make_pair(i,j);
			}
			else if(s[i][j]>='0'&&s[i][j]<='8')
			{
				pr[s[i][j]-'0']=make_pair(i,j);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		c+=bfs(pr[i-1].first,pr[i-1].second,i);
	}
	cout<<c<<endl;
	return 0;
}