#include<iostream>
using namespace std;

const int n=8;
const int Free=1;
const int notFree=-1;

int row[n],col[n],dpos[2*n-1],dneg[2*n-1];
bool X[n][n];

void initialize()
{
	for(int i=0;i<n;i++)row[i]=col[i]=Free;
	for(int i=0;i<2*n-1;i++)dpos[i]=dneg[i]=Free;
	return;
}

void printbord()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(X[i][j]&&row[i]!=j)return;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<(row[i]==j?"Q":".");
		}
		cout<<endl;
	}
	return;
}

void recursive(int i)
{
	if(i==n){printbord();return;}
	
	for(int j=0;j<n;j++)
	{
		if(col[j]==notFree||dpos[i+j]==notFree||dneg[i-j+n-1]==notFree)continue;
		
		row[i]=j;col[j]=dpos[i+j]=dneg[i-j+n-1]=notFree;
		
		recursive(i+1);
		
		col[j]=dpos[i+j]=dneg[i-j+n-1]=Free;
	}
	return;
}

int main()
{
	initialize();
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)X[i][j]=false;
	
	int k;cin>>k;
	int r,c;
	for(int i=0;i<k;i++)
	{
		cin>>r>>c;
		X[r][c]=true;
	}
	
	recursive(0);
	
	return 0;
}