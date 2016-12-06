#include<iostream>
#include<algorithm>
using namespace std;
const int INF=1<<30;
int main() {
	int n,m;cin>>n>>m;
	int c[20],t[50001];
	for(int i=0;i<m;i++)cin>>c[i];
	for(int i=1;i<=n;i++)t[i]=INF;
	t[0]=0;
	for(int i=0;i<m;i++)
	{
		for(int j=c[i];j<=n;j++)
		{
			t[j]=min(t[j],t[j-c[i]]+1);
		}
	}
	cout<<t[n]<<endl;
	return 0;
}