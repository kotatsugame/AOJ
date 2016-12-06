#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,a,b) for(int i=(a);i<=(b);i++)
#define P pair<int,int>
using namespace std;

int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,-1,-1,-1,0,1,1,1};

int h,w;
int a[1002][1002];
string s[1002];

int main()
{
	cin>>h>>w;
	rep(i,h)cin>>s[i];
	vector<P> f[2];
	int now=0,pre=1,ans=0;
	bool flag;
	rrep(i,1,h-2)
	{
		rrep(j,1,w-2)
		{
			rep(k,8)if(s[i+dx[k]][j+dy[k]]=='.')a[i][j]++;
			if(s[i][j]!='.'&&s[i][j]-'0'<=a[i][j])f[now].pb(mp(i,j));
		}
	}
	while(1)
	{
		flag=false;
		now=!now;
		pre=!pre;
		f[now].clear();
		rep(i,f[pre].size())
		{
			P p=f[pre][i];
			if(s[p.fi][p.se]!='.'&&s[p.fi][p.se]-'0'<=a[p.fi][p.se])
			{
				flag=true;
				s[p.fi][p.se]='.';
				rep(j,8)
				{
					int tx=p.fi+dx[j];
					int ty=p.se+dy[j];
					if(tx<=0||tx>=h-1||ty<=0||ty>=w-1)continue;
					a[tx][ty]++;
					if(s[tx][ty]!='.'&&s[tx][ty]-'0'==a[tx][ty])f[now].pb(mp(tx,ty));
				}
			}
		}
		if(flag)ans++;
		else break;
	}
	cout<<ans<<endl;
	return 0;
}