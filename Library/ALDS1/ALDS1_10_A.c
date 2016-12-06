#include<cstdio>
main(){int n,i=1,f[45]={1,1};for(scanf("%d",&n);++i<=n;f[i]=f[i-1]+f[i-2]);printf("%d\n",f[n]);}