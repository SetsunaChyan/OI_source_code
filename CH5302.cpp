#include <cstdio>
#include <cstring>
#include <memory.h>

const long long MOD=1e9;
char s[301];
int n;
long long f[301][301];

long long dp(int l,int r)
{
	if(l>r) return 0;
	if(l==r) return 1;
	if(~f[l][r]) return f[l][r];
	if(s[l]!=s[r]) return f[l][r]=0;
	f[l][r]=0;
	for(int k=l+1;k<=r-1;k++)
		f[l][r]=(f[l][r]+dp(l+1,k)*dp(k+1,r))%MOD;
	return f[l][r];
}

int main()
{
	memset(f,-1,sizeof(f));
	scanf("%s",s);
	n=strlen(s);
	printf("%lld",dp(0,n-1));
	return 0;
}