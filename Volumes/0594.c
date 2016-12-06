#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int w,h,n;cin>>w>>h>>n;
	int sx,sy;cin>>sx>>sy;
	int x,y;
	int all=0;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		if((sx-x)*(sy-y)>=0)
		{
			all+=max(abs(sx-x),abs(sy-y));
		}
		else
		{
			all+=abs(sx-x)+abs(sy-y);
		}
		sx=x;sy=y;
	}
	cout<<all<<endl;
	return 0;
}