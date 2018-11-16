#include <cstdio>
#include <memory.h>

char s[1001];
int n,p[26];

int main()
{
	scanf("%d%s",&n,s);
	int flag=0;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]!=s[i+1])
		{
			printf("YES\n%c%c\n",s[i],s[i+1]);
			flag=1;
			break;
		}
	}
	if(!flag) printf("NO");
	return 0;
}