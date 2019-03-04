#include <stdio.h>
#include <string.h>

char a[61];
int n,i;

int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",a);
		if(a[strlen(a)-1]%2==0)
			printf("even\n");
		else
			printf("odd\n");		
	}
	return 0;
} 
