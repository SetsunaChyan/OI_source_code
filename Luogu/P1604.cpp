#include <cstdio>
#include <memory.h>
#include <cstring>

const int MAXN=2005;
int a[MAXN],b[MAXN],n;
char s[MAXN];

void read(int a[])
{
	memset(a,0,sizeof(a));
	scanf("%s",s);
	int l=strlen(s);
	for(int i=0,j=MAXN-l;i<l;i++,j++)
	{
		if(s[i]>='A'&&s[i]<='Z')
			a[j]=s[i]-'A'+10;
		else
			a[j]=s[i]-'0';
	}
}

inline int max(int a,int b)
{
	return a>b?a:b;
}


int main()
{
	scanf("%d",&n);
	read(a);read(b);
	for(int i=MAXN-1;i>=1;i--)
	{
		a[i]+=b[i];
		a[i-1]+=a[i]/n;
		a[i]%=n;
	}
	int i;
	for(i=0;i<MAXN;i++) if(a[i]!=0) break;
	for(;i<MAXN;i++)
		if(a[i]>=10) printf("%c",a[i]-10+'A'); else printf("%d",a[i]);
	printf("\n");
	return 0;
}