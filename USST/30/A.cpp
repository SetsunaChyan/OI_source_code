#include <cstdio>
#include <memory.h>

int n,flag=0;
char s[105];

int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		if(s[0]=='H'||s[0]=='h') flag=1;
	}	
	if(flag) printf("hard"); else printf("easy");
	return 0;
}

