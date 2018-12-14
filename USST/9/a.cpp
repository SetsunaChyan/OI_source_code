#include <cstdio>
#include <cstring>
#include <memory.h>
#include <cmath>

char s[100050];
int cnt[26];

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

bool is_prime(int x)
{
	if(x==0) return false;
	int t=sqrt(x);
	for(int i=2;i<=t;i++)
		if(x%i==0) return false;
	return true;
}

int main()
{
	memset(cnt,0,sizeof(cnt));
	scanf("%s",s);
	int l=strlen(s),maxn=0,minn=0x3f3f3f3f;
	for(int i=0;i<l;i++)
	{
		int p=s[i]-'a';
		cnt[p]++;
		minn=min(minn,cnt[p]);
		maxn=max(maxn,cnt[p]);
	}
	if(is_prime(maxn-minn))
		printf("Lucky Word\n%d",maxn-minn);
	else
		printf("No Answer\n%d",0);
	return 0;
}