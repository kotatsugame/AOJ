#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n,S;cin>>n>>S;
	int a[100000];
	for(int i=0;i<n;i++)cin>>a[i];
	int ans=n+1;
	for(int s=0,t=0,sum=0;;ans=min(ans,t-s),sum-=a[s++])
	{
		while(t<n&&sum<S)sum+=a[t++];
		if(sum<S)break;
	}
	if(ans>n)cout<<0<<endl;
	else cout<<ans<<endl;
	return 0;
}