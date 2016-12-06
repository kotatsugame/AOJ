#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int x,y;
	for(int i=0;i<k;i++)
	{
		cin>>x>>y;
		x=min(x,n-x+1);
		y=min(y,n-y+1);
		cout<<(min(x,y)%3?min(x,y)%3:3)<<endl;
	}
	return 0;
}