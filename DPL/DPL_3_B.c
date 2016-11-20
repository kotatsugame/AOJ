#include<iostream>
#include<stack>
#include<algorithm>
#define fi first
#define se second
using namespace std;
const int M=1400;
int h,w;
int T[M][M+1];
int get(int size)
{
	stack<pair<int,int>>s;
	int maxv=0;
	pair<int,int>r,p;
	int t;
	
	for(int i=0;i<=w;i++)
	{
		r.fi=T[size][i];
		r.se=i;
		if(s.empty())s.push(r);
		else
		{
			if(s.top().fi<r.fi)s.push(r);
			else if(s.top().fi>r.fi)
			{
				t=i;
				while(!s.empty()&&s.top().fi>r.fi)
				{
					p=s.top();s.pop();
					maxv=max(maxv,p.fi*(i-p.se));
					t=p.se;
				}
				r.se=t;
				s.push(r);
			}
		}
	}
	return maxv;
}

int main()
{
	cin>>h>>w;
	int c[M][M];
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin>>c[i][j];
		}
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			T[i][j]=(c[i][j]?0:i>0?T[i-1][j]+1:1);
		}
		T[i][w]=0;
	}
	int maxv=0;
	for(int i=0;i<h;i++)
	{
		maxv=max(maxv,get(i));
	}
	cout<<maxv<<endl;
	return 0;
}