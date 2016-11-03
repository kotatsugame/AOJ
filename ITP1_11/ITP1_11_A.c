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
		return;
	}
};

int main() {
	dice d;
	d.in();
	string s;cin>>s;
	for(int i=0;i<s.length();i++)d.r(s[i]);
	cout<<d.l[0]<<endl;
	return 0;
}