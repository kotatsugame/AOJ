#include <iostream>
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
	dice d[2];bool flag=true;
	d[0].in();d[1].in();int i;
	for(i=1;d[0].l[0]==d[0].l[1]&&i<5;i++)d[0].r('R');
	if(d[0].l[0]==d[0].l[1])for(flag=false,i=1;d[0].l[5]==d[0].l[1]&&i<5;i++)d[0].r('R');
	if(!flag)d[0].r_tf(d[0].l[5],d[0].l[1]);flag=true;
	d[1].r_tf(d[0].l[0],d[0].l[1]);
	for(int i=2;i<6;i++)if(d[0].l[i]!=d[1].l[i])flag=false;
	if(flag)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}