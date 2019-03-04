#include <stdio.h>
#include <string.h>

char a[255];
int n,i;

int main()
{
	scanf("%d",&n);
	scanf("%s",a);
	for(i=0;i<strlen(a);i++)
	{
		a[i]=(a[i]-'a'+n)%26+'a';
	}
	printf("%s",a);
	return 0;
}
