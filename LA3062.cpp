#include <cstdio>

const int MAXN=1e6+50;
int n,kmp[MAXN];
char s[MAXN];

void getfail(char *s)
{
	int l=n;
	kmp[0]=0;kmp[1]=0;
	for(int i=1;i<n;i++)
	{
		int j=kmp[i];
		while(j&&s[i]!=s[j]) j=kmp[j];
		kmp[i+1]=s[i]==s[j]?j+1:0;
	}
}

int main()
{
	int t=0;
	while(~scanf("%d",&n),n)
	{
		t++;
		scanf("%s",s);
		getfail(s);
		printf("Test case #%d\n",t);
		for(int i=2;i<=n;i++)
			if(kmp[i]&&kmp[i]%(i-kmp[i])==0) printf("%d %d\n",i,kmp[i]/(i-kmp[i])+1);
		printf("\n");
	}
	return 0;
}