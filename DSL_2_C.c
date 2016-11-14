#include <iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX=500000;
const int NIL=-1;

class node
{
public:
	int loc;//location
	int l;
	int r;
};

class point
{
public:
	int id;
	int x;
	int y;
	point(){}
	point(int inid,int inx,int iny):id(inid),x(inx),y(iny){}
};

int n;
point P[MAX];
node T[MAX];
int np=0;

bool lessX(const point &p1,const point &p2)
{
	return p1.x<p2.x;
}
bool lessY(const point &p1,const point &p2)
{
	return p1.y<p2.y;
}

int make2Dtree(int l,int r,int depth)
{
	if(l>=r)return NIL;
	int mid=(l+r)/2;
	int t=np++;
	
	if(depth%2==0)sort(P+l,P+r,lessX);
	else sort(P+l,P+r,lessY);
	
	T[t].loc=mid;
	T[t].l=make2Dtree(l,mid,depth+1);
	T[t].r=make2Dtree(mid+1,r,depth+1);
	
	return t;
}

void find(int v,int sx,int tx,int sy,int ty,int depth,vector<int> &ans)
{
	int x=P[T[v].loc].x;
	int y=P[T[v].loc].y;
	if(sx<=x&&x<=tx&&sy<=y&&y<=ty)ans.push_back(P[T[v].loc].id);
	
	if(depth%2==0)
	{
		if(T[v].l!=NIL&&sx<=x)find(T[v].l,sx,tx,sy,ty,depth+1,ans);
		if(T[v].r!=NIL&&x<=tx)find(T[v].r,sx,tx,sy,ty,depth+1,ans);
	}
	else
	{
		if(T[v].l!=NIL&&sy<=y)find(T[v].l,sx,tx,sy,ty,depth+1,ans);
		if(T[v].r!=NIL&&y<=ty)find(T[v].r,sx,tx,sy,ty,depth+1,ans);
	}
	
	return;
}

int main() {
	cin>>n;int x,y;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		P[i]=point(i,x,y);
		T[i].l=T[i].r=NIL;
	}
	np=0;
	int root=make2Dtree(0,n,0);
	int q;cin>>q;
	int sx,tx,sy,ty;
	vector<int> ans;
	for(int i=0;i<q;i++)
	{
			scanf("%d%d%d%d",&sx,&tx,&sy,&ty);
			ans.clear();
			find(root,sx,tx,sy,ty,0,ans);
			sort(ans.begin(),ans.end());
			for(int j=0;j<ans.size();j++)printf("%d\n",ans[j]);
			printf("\n");
	}
	return 0;
}