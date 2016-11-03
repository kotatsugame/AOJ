#include <iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;

ll f(int a,int b)
{
	return b?f(b,a%b):a;
}

int main() {
	int n;cin>>n;ll a,b;cin>>a;
	for(int i=0;i<n-1;i++)
	{
		cin>>b;
		a=a*b/f(max(a,b),min(a,b));
	}
	cout<<a<<endl;
	return 0;
}