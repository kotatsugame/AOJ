#include <iostream>
using namespace std;
const int NIL=-1;
const int MAXt=100000;

class Node{
public:
	int parent;
	int left;
	int right;
};

Node T[MAXt];
int Depth[MAXt];

int getDepth(int u)
{
	int d=0,ub=u;
	while(T[u].parent!=NIL)
	{
		u=T[u].parent;
		d++;
	}
	return Depth[ub]=d;
}

void setDepth(int u,int p)
{
	Depth[u]=p;
	if(T[u].right!=NIL)setDepth(T[u].right,p);
	if(T[u].left!=NIL)setDepth(T[u].left,p+1);
	return;
}

void print(int u)
{
	cout<<"node "<<u<<": parent = "<<T[u].parent<<", depth = "<<Depth[u]<<", ";
	if(T[u].parent==NIL)cout<<"root";
	else if(T[u].left==NIL)cout<<"leaf";
	else cout<<"internal node";
	cout<<", [";
	for(int i=0,c=T[u].left;c!=NIL;i++,c=T[c].right)
	{
		if(i)cout<<", ";
		cout<<c;
	}
	cout<<"]"<<endl;
	return;
}

int main() {
	int n;cin>>n;
	int id,k,c,l,root;
	for(int i=0;i<n;i++)T[i].parent=T[i].left=T[i].right=NIL;
	for(int i=0;i<n;i++)
	{
		cin>>id>>k;
		for(int j=0;j<k;j++)
		{
			cin>>c;
			if(j)
			{
				T[l].right=c;
				T[c].parent=id;
				l=c;
			}
			else
			{
				T[id].left=c;
				T[c].parent=id;
				l=c;
			}
		}
	}
	for(int i=0;i<n;i++)if(T[i].parent==NIL){root=i;break;}
	setDepth(root,0);
	for(int i=0;i<n;i++)print(i);
	return 0;
}