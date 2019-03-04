#include <cstdio>
#include <cstring>

const int MAXN=1000005;
char s1[MAXN],s2[MAXN];
int f[MAXN];

void getfail(char *s)
{
	f[0]=0;f[1]=0;
	int l=strlen(s);
	for(int i=1;i<l;i++)
	{
		int j=f[i];
		while(j&&s[j]!=s[i]) j=f[j];
		f[i+1]=s[j]==s[i]?j+1:0;
	}
}

void kmp(char *s1,char *s2)
{
	int l1=strlen(s1),l2=strlen(s2),j=0;
	getfail(s2);
	for(int i=0;i<l1;i++)
	{
		while(j&&s1[i]!=s2[j]) j=f[j];
		if(s1[i]==s2[j]) j++;
		if(j==l2) printf("%d\n",i-l2+2);
	}
}

int main()
{
	scanf("%s %s",s1,s2);
	kmp(s1,s2);
	int l=strlen(s2);
	for(int i=1;i<=l;i++)
		printf("%d ",f[i]);
	return 0;	
}