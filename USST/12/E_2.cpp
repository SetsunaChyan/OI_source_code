#include <cstdio>
#include <stdlib.h>
#include <time.h>

char p[4]={'D','U','L','R'};
char s[40050]="";

int main()
{
	srand(time(0));
	for(int i=0;i<40000;i++) s[i]=p[rand()%4];
	s[40000]='\0';
	int n;
	scanf("%d",&n);
	while(n--) puts(s);		
	return 0;
}