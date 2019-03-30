#include <cstdio>
#include <cstring>

char s[100005];
int n;

int main()
{
	scanf("%s",s);
	n=strlen(s);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int x;
		if(s[i]>='A'&&s[i]<='V') 
			x=s[i]-'A'+10;
		else
			x=s[i]-'0';
		while(x)
		{
			if(x&1) ans++;
			x>>=1;
		}
	}
	printf("%d",ans);
	return 0;
}
