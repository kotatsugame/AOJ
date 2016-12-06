#include<iostream>
#include<algorithm>
#define fi first
#define se second
const int in=1;
const int out=0;

using namespace std;

int main()
{
	int n,t;cin>>n>>t;
	vector<pair<int,int>> a;
	int it,ot;
	for(int i=0;i<n;i++)
	{
		cin>>it>>ot;
		a.push_back(make_pair(it,in));
		a.push_back(make_pair(ot,out));
	}
	sort(a.begin(),a.end(),[](const pair<int,int> s1,const pair<int,int> s2)
	{return s1.fi==s2.fi?s1.se<s2.se:s1.fi<s2.fi;});
	
	int maxm=0,now=0;
	
	for(int i=0;i<a.size();i++)
	{
		pair<int,int> s;
		s=a[i];
		if(s.se==out)
		{
			now--;
		}
		else
		{
			now++;
			maxm=max(maxm,now);
		}
	}
	
	cout<<maxm<<endl;
	return 0;
}