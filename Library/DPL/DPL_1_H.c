#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
pair<ll,ll> ps[1<<20];
const ll INF=1e15;
int main()
{
	int n;cin>>n;
	ll W;cin>>W;
	ll v[40],w[40];
	for(int i=0;i<n;i++)cin>>v[i]>>w[i];
	int n2=n/2;
	for(int i=0;i<1<<n2;i++)
	{
		ll sw=0,sv=0;
		for(int j=0;j<n2;j++)
		{
			if(i>>j&1)
			{
				sw+=w[j];
				sv+=v[j];
			}
		}
		ps[i]=make_pair(sw,sv);
	}
	sort(ps,ps+(1<<n2));
	int m=1;
	for(int i=1;i<1<<n2;i++)
	{
		if(ps[m-1].second<ps[i].second)
		{
			ps[m++]=ps[i];
		}
	}
	
	ll res=0;
	for(int i=0;i<1<<(n-n2);i++)
	{
		ll sw=0,sv=0;
		for(int j=0;j<n-n2;j++)
		{
			if(i>>j&1)
			{
				sw+=w[n2+j];
				sv+=v[n2+j];
			}
		}
		if(sw<=W)
		{
			ll tv=(lower_bound(ps,ps+m,make_pair(W-sw,INF))-1)->second;
			res=max(res,sv+tv);
		}
	}
	cout<<res<<endl;
	return 0;
}