#include <stdio.h>
#include <string.h>

enum strtype
{
	BFS,
	FS,
	ZS,
	XS
};

char s[255],s1[255];

strtype lx(char s[255])
{
	int i,l;
	scanf("%s",s);
	l=strlen(s); 
	for(i=0;i<l;i++)
	{
		if(s[i]=='.') return XS;	
		if(s[i]=='/') return FS;	
		if(s[i]=='%') return BFS;	
	}
	return ZS;
}

int main()
{
	strtype a;
	long long x,x1,x2;
	int i,l;
	a=lx(s);
	if(a==ZS)
	{
		l=strlen(s)-1;
		i=0;
		while(s[l]=='0') l--;
		if(l<0) printf("0");
		for(i=l;i>=0;i--)
			printf("%c",s[i]);
	}
	if(a==BFS)
	{
		sscanf(s,"%lld",&x1);
		sprintf(s1,"%lld",x1);
		l=strlen(s1)-1;
		i=0;
		while(s1[l]=='0') l--;
		if(l<0) printf("0");
		for(i=l;i>=0;i--)
			printf("%c",s1[i]);
		printf("%%");
	}
	if(a==FS)
	{
		sscanf(s,"%lld/%lld",&x1,&x2);
		sprintf(s1,"%lld",x1);
		l=strlen(s1)-1;
		i=0;
		while(s1[l]=='0') l--;
		if(l<0) printf("0");
		for(i=l;i>=0;i--)
			printf("%c",s1[i]);
		printf("/");
		sprintf(s1,"%lld",x2);
		l=strlen(s1)-1;
		i=0;
		while(s1[l]=='0') l--;
		if(l<0) printf("0");
		for(i=l;i>=0;i--)
			printf("%c",s1[i]);
	}
	if(a==XS)
	{
		sscanf(s,"%lld.%lld",&x1,&x2);
		sprintf(s1,"%lld",x1);
		l=strlen(s1)-1;
		i=0;
		while(s1[l]=='0') l--;
		if(l<0) printf("0");
		for(i=l;i>=0;i--)
			printf("%c",s1[i]);
		printf(".");
		sprintf(s1,"%lld",x2);
		l=strlen(s1)-1;
		i=0;
		while(s1[l]=='0') l--;
		if(l<0) printf("0");
		for(i=l;i>=0;i--)
			printf("%c",s1[i]);
	}
	return 0;
} 
