#include <iostream>
using namespace std;
const int NIL=-1;
const int MAXt=10000;

class node
{
public:
	int p;
	int l;
	int r;
};

node T[MAXt];
int H[MAXt];

int seth(int u)
{
	int h1=0,h2=0;
	if(T[u].r!=NIL)h1=seth(T[u].r)+1;
	if(T[u].l!=NIL)h2=seth(T[u].l)+1;
	return H[u]=h1>h2?h1:h2;
}

int D[MAXt];

void setdp(int u,int d)
{
	if(u==NIL)return;
	D[u]=d++;
	setdp(T[u].l,d);
	setdp(T[u].r,d);
	return;
}
int getdg(int u)//degree
{
	int d=0;
	if(T[u].l!=NIL)d++;
	if(T[u].r!=NIL)d++;
	return d;
}

int gets(int u)//sibling
{
	if(T[u].p!=NIL)
	{
		if(T[T[u].p].l!=u&&T[T[u].p].l!=NIL)return T[T[u].p].l;
		if(T[T[u].p].r!=u&&T[T[u].p].r!=NIL)return T[T[u].p].r;
	}
	return NIL;
}

void print(int u)
{
	cout<<"node "<<u<<": parent = "<<T[u].p<<", sibling = "<<gets(u)<<", degree = "<<getdg(u)
	<<", depth = "<<D[u]<<", height = "<<H[u]<<", ";
	if(T[u].p==NIL)cout<<"root";
	else if(T[u].l==NIL&&T[u].r==NIL)cout<<"leaf";
	else cout<<"internal node";
	cout<<endl;
}

int main() {
	int n;cin>>n;
	int id,r,l,root;
	for(int i=0;i<n;i++)T[i].p=NIL;
	for(int i=0;i<n;i++)
	{
		cin>>id>>l>>r;
		T[id].l=l;
		if(l!=NIL)T[l].p=id;
		T[id].r=r;
		if(r!=NIL)T[r].p=id;
	}
	for(int i=0;i<n;i++)if(T[i].p==NIL){root=i;break;}
	setdp(root,0);
	seth(root);
	for(int i=0;i<n;i++)print(i);
	return 0;
}