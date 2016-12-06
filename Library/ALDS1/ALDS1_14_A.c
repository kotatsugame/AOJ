#include <iostream>
#include<string>
using namespace std;

int main() {
	string t,p;
	cin>>t>>p;
	int ts=t.size(),ps=p.size();
	bool flag;
	for(int i=0;i<=ts-ps;i++)
	{
		flag=true;
		for(int j=0;j<ps;j++)
		{
			if(t[i+j]!=p[j])
			{
				flag=false;
				break;
			}
		}
		if(flag)cout<<i<<endl;
	}
	return 0;
}