#include <iostream>
#include<algorithm>
using namespace std;
static const int MAX=100;
static const long long int INFTY=1LL<<32;

int n;
long long int M[MAX][MAX];

void floyd()
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			if(M[i][k]==INFTY)continue;
			for(int j=0;j<n;j++)
			{
				if(M[k][j]==INFTY)continue;
				M[i][j]=min(M[i][j],M[i][k]+M[k][j]);
			}
		}
	}
	return;
}

int main() {
	cin>>n;int e,u,v,d;cin>>e;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)M[i][j]=i==j?0:INFTY;
	for(int i=0;i<e;i++)
	{
		cin>>u>>v>>d;
		M[u][v]=d;
	}
	floyd();
	bool flag=false;
	for(int i=0;i<n;i++)if(M[i][i]<0){flag=true;break;}
	if(flag)cout<<"NEGATIVE CYCLE"<<endl;
	else
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(j)cout<<" ";
				if(M[i][j]==INFTY)cout<<"INF";
				else cout<<M[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}