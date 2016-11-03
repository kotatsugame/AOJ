#include <iostream>
using namespace std;
const int MAXt=10000;

int n,pos=0,poss=0;
int pre[MAXt],in[MAXt],post[MAXt];

void rec(int l,int r)
{
	if(l>=r)return;
	int root=pre[pos++];
	int i;
	for(i=0;i<n;i++)if(in[i]==root)break;
	rec(l,i);
	rec(i+1,r);
	post[poss++]=root;
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++)cin>>pre[i];
	for(int i=0;i<n;i++)cin>>in[i];
	rec(0,n);
	for(int i=0;i<n;i++)
	{
		if(i)cout<<" ";
		cout<<post[i];
	}
	cout<<endl;
	return 0;
}