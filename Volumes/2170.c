#include<iostream>
using namespace std;

const int MAX=100000;

bool marked[MAX];
int parent[MAX];

int find(int s)
{
	int i=s;
	while(!marked[i])i=parent[i];
	return i;
}

int main()
{
	int n,q;
	while(cin>>n>>q,n)
	{
		int a;char c;
		for(int i=1;i<n;i++)
		{
			cin>>a;a--;
			parent[i]=a;
			marked[i]=false;
		}
		parent[0]=0;
		marked[0]=true;
		long long int sum=0;
		for(int i=0;i<q;i++)
		{
			cin>>c>>a;a--;
			if(c=='Q')
			{
				sum+=(long long int)find(a)+1;
			}
			else
			{
				marked[a]=true;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}