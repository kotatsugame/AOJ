#include <iostream>
#include<algorithm>
using namespace std;
class dice
{
public:
	int l[6];//label
	void in()
	{
		for(int i=0;i<6;i++)cin>>l[i];
	}
	void r(char a)//roll
	{
		if(a=='S')
		{
			int sto=l[0];
			l[0]=l[4];
			l[4]=l[5];
			l[5]=l[1];
			l[1]=sto;
		}
		else if(a=='N')
		{
			int sto=l[0];
			l[0]=l[1];
			l[1]=l[5];
			l[5]=l[4];
			l[4]=sto;
		}
		else if(a=='E')
		{
			int sto=l[0];
			l[0]=l[3];
			l[3]=l[5];
			l[5]=l[2];
			l[2]=sto;
		}
		else if(a=='W')
		{
			int sto=l[0];
			l[0]=l[2];
			l[2]=l[5];
			l[5]=l[3];
			l[3]=sto;
		}
		else if(a=='R')
		{
			r('N');r('E');r('S');
		}
		else if(a=='L')
		{
			r('N');r('W');r('S');
		}
		return;
	}
	void r_tf(int t,int f)
	{
		int i;for(i=0;i<6;i++)if(l[i]==t)break;
		if(i==1)r('N');
		else if(i==2)r('W');
		else if(i==3)r('E');
		else if(i==4)r('S');
		else if(i==5)r('N'),r('N');
		
		for(i=1;i<5;i++)if(l[i]==f)break;
		if(i==2)r('L');
		else if(i==3)r('R');
		else if(i==4)r('L'),r('L');
		
		return;
	}
};

int main() {
	int n;cin>>n;
	dice d[100];bool flag=true,flags=false,flagall=false;
	int i;for(i=0;i<n;i++)d[i].in();int a[6],b[6];
	for(int j=0;j<n;j++)for(int k=j+1;k<n;k++){
	for(int l=0;l<6;l++){a[l]=d[j].l[l];b[l]=d[k].l[l];}sort(a,a+6);sort(b,b+6);
	for(int l=0;l<6;l++)if(a[l]!=b[l])flag=false;if(!flag){flag=true;continue;}
	for(i=1;d[j].l[0]==d[j].l[1]&&i<5;i++)d[j].r('R');
	if(d[j].l[0]==d[j].l[1])for(flags=true,i=1;d[j].l[5]==d[j].l[1]&&i<5;i++)d[j].r('R');
	if(flags)d[j].r_tf(d[j].l[5],d[j].l[1]);flags=false;
	d[k].r_tf(d[j].l[0],d[j].l[1]);
	for(int i=2;i<6;i++)if(d[j].l[i]!=d[k].l[i])flag=false;
	if(flag)flagall=true;
	flag=true;
	}
	if(flagall)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}