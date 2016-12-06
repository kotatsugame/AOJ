#include<iostream>
using namespace std;
int main()
{
	int a[4001]={};
	for(int i=0;i<=1000;i++)
	{
		for(int j=0;j<=1000;j++)
		{
			a[i+j]++;
		}
	}
	int n;
	while(cin>>n){
	long long int all=0;
	for(int i=0;i<=1000;i++)
	{
		for(int j=0;j<=1000&&j<=n-i;j++)
		{
			all+=a[n-i-j];
		}
	}
	cout<<all<<endl;}
	return 0;
}