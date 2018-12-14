#include <cstdio>
#include <cstring>

char s[100];
int flag=1;

int main()
{
	scanf("%s",s);
	if(strlen(s)!=11||s[0]!='1') flag=0;
	for(int i=0;i<strlen(s);i++)
		if(s[i]<'0'||s[i]>'9') flag=0;
	if(flag) printf("yes"); else printf("no");
	return 0;
}