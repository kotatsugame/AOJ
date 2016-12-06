#include<iostream>
#include<algorithm>
using namespace std;
const int M=100;
int main() {
	int n,m;cin>>n>>m;
	int v[M],w[M],c[M+1][10001];
	bool G[M][10001];
	for(int i=0;i<n;i++)cin>>v[i]>>w[i];
	for(int i=0;i<n;i++)for(int j=0;j<=m;j++)c[i][j]=0,G[i][j]=false;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			c[i][j]=c[i-1][j];
			if(w[i]>j)continue;
			if(v[i]+c[i-1][j-w[i]]>c[i][j])
			{
				c[i][j]=c[i-1][j-w[i]]+v[i];
				G[i][j]=true;
			}
		}
	}
	
	vector<int> sel;
	for(int i=n-1,ww=m;i>=0;i--)
	{
		if(G[i][ww])
		{
			sel.push_back(i);
			ww-=w[i];
		}
	}
	reverse(sel.begin(),sel.end());
	cout<<c[n-1][m]<<endl;
	//for(auto it:sel)cout<<it+1<<endl;
	return 0;
}