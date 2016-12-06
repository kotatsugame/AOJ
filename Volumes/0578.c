#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;cin>>n;
	string s;cin>>s;
	string o[100];
	for(int i=0;i<n;i++)cin>>o[i];
	int c=0;
	bool flag;
	for(int i=0;i<n;i++)
	{
		flag=false;
		for(int j=1;j*(s.length()-1)<o[i].length();j++)
		{
			for(int k=0;k+j*(s.length()-1)<o[i].length();k++)
			{
				string now="";
				for(int l=0;l<s.length();l++)
				{
					now+=o[i][j*l+k];
				}
				if(now==s)
				{
					c++;
					flag=true;
					break;
				}
			}
			if(flag)break;
		}
	}
	cout<<c<<endl;
	return 0;
}