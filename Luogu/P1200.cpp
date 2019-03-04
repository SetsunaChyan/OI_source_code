#include <stdio.h>
#include <string.h>

char a[255],b[255];

int main()
{
	int i,x1=1,x2=1;
	scanf("%s %s",a,b);
	for(i=0;i<strlen(a);i++) x1*=(a[i]-'A'+1)%47; 
	for(i=0;i<strlen(b);i++) x2*=(b[i]-'A'+1)%47;
	if(x1%47==x2%47)
		printf("GO\n");
	else
		printf("STAY\n");
	return 0;
}
