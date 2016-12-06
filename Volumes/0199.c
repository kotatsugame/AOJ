#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

const int INF=1<<15;

int main()
{
	int n,m;
	while(cin>>n>>m,n)
	{
		string s="";
		int d[100];
		for(int i=0;i<n;i++)
		{
			s+='#';
			d[i]=INF;
		}
		
		char in;
		for(int ii=0;ii<m;ii++)
		{
			cin>>in;
			if(in=='A')
			{
				for(int i=0;i<n;i++)if(s[i]=='#')
				{
					s[i]='A';
					d[i]=0;
					for(int j=i-1;j>=0;j--)
					{
						if(d[j]>d[j+1]+1)d[j]=d[j+1]+1;
						else break;
					}
					for(int j=i+1;j<n;j++)
					{
						if(d[j]>d[j-1]+1)d[j]=d[j-1]+1;
						else break;
					}
					break;
				}
			}
			else if(in=='B')
			{
				bool flag=false;
				for(int i=n-1;i>=0;i--)
				{
					if(s[i]=='#')
					{
						if(i==n-1&&s[i-1]!='A')
						{
							s[i]='B';
							d[i]=0;
							for(int j=i-1;j>=0;j--)
							{
								if(d[j]>d[j+1]+1)d[j]=d[j+1]+1;
								else break;
							}
							for(int j=i+1;j<n;j++)
							{
								if(d[j]>d[j-1]+1)d[j]=d[j-1]+1;
								else break;
							}
							flag=true;
							break;
						}
						else if(i==0&&s[i+1]!='A')
						{
							s[i]='B';
							d[i]=0;
							for(int j=i-1;j>=0;j--)
							{
								if(d[j]>d[j+1]+1)d[j]=d[j+1]+1;
								else break;
							}
							for(int j=i+1;j<n;j++)
							{
								if(d[j]>d[j-1]+1)d[j]=d[j-1]+1;
								else break;
							}
							flag=true;
							break;
						}
						else if(s[i-1]!='A'&&s[i+1]!='A')
						{
							s[i]='B';
							d[i]=0;
							for(int j=i-1;j>=0;j--)
							{
								if(d[j]>d[j+1]+1)d[j]=d[j+1]+1;
								else break;
							}
							for(int j=i+1;j<n;j++)
							{
								if(d[j]>d[j-1]+1)d[j]=d[j-1]+1;
								else break;
							}
							flag=true;
							break;
						}
					}
				}
				if(!flag)
				{
					for(int i=n-1;i>=0;i--)if(s[i]=='#')
					{
						s[i]='B';
							d[i]=0;
						for(int j=i-1;j>=0;j--)
						{
							if(d[j]>d[j+1]+1)d[j]=d[j+1]+1;
							else break;
						}
						for(int j=i+1;j<n;j++)
						{
							if(d[j]>d[j-1]+1)d[j]=d[j-1]+1;
							else break;
						}
						break;
					}
				}
			}
			else if(in=='C')
			{
				bool flag=false;
				for(int i=0;i<n;i++)
				{
					if(s[i]!='#')
					{
						if(i==0&&s[i+1]=='#')
						{
							s[i+1]='C';
							d[i+1]=0;
							for(int j=i;j>=0;j--)
							{
								if(d[j]>d[j+1]+1)d[j]=d[j+1]+1;
								else break;
							}
							for(int j=i+2;j<n;j++)
							{
								if(d[j]>d[j-1]+1)d[j]=d[j-1]+1;
								else break;
							}
							flag=true;
							break;
						}
						else if(i==n-1&&s[i-1]=='#')
						{
							s[i-1]='C';
							d[i-1]=0;
							for(int j=i-2;j>=0;j--)
							{
								if(d[j]>d[j+1]+1)d[j]=d[j+1]+1;
								else break;
							}
							for(int j=i;j<n;j++)
							{
								if(d[j]>d[j-1]+1)d[j]=d[j-1]+1;
								else break;
							}
							flag=true;
							break;
						}
						else
						{
							if(s[i+1]=='#')
							{
								s[i+1]='C';
								d[i+1]=0;
								for(int j=i;j>=0;j--)
								{
									if(d[j]>d[j+1]+1)d[j]=d[j+1]+1;
									else break;
								}
								for(int j=i+2;j<n;j++)
								{
									if(d[j]>d[j-1]+1)d[j]=d[j-1]+1;
									else break;
								}
								flag=true;
								break;
							}
							if(s[i-1]=='#')
							{
								s[i-1]='C';
								d[i-1]=0;
								for(int j=i-2;j>=0;j--)
								{
									if(d[j]>d[j+1]+1)d[j]=d[j+1]+1;
									else break;
								}
								for(int j=i;j<n;j++)
								{
									if(d[j]>d[j-1]+1)d[j]=d[j-1]+1;
									else break;
								}
								flag=true;
								break;
							}
						}
					}
				}
				if(!flag)
				{
					s[n/2]='C';
					d[n/2]=0;
					for(int j=n/2-1;j>=0;j--)
					{
						if(d[j]>d[j+1]+1)d[j]=d[j+1]+1;
						else break;
					}
					for(int j=n/2+1;j<n;j++)
					{
						if(d[j]>d[j-1]+1)d[j]=d[j-1]+1;
						else break;
					}
				}
			}
			else
			{
				int ma=0;
				for(int i=1;i<n;i++)
				{
					if(d[ma]<d[i])ma=i;
				}
				s[ma]='D';
				d[ma]=0;
				for(int j=ma-1;j>=0;j--)
				{
					if(d[j]>d[j+1]+1)d[j]=d[j+1]+1;
					else break;
				}
				for(int j=ma+1;j<n;j++)
				{
					if(d[j]>d[j-1]+1)d[j]=d[j-1]+1;
					else break;
				}
			}
		}
		
		cout<<s<<endl;
	}
	
	return 0;
}