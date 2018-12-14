#include <cstdio>
#include <cstring>

char s[100005];

int main()
{
	while(~scanf("%s",s))
	{
		int l=strlen(s)-3;
		for(int i=0;i<l;i++)
		{
			if(s[i]=='s'&&s[i+1]=='h'&&s[i+2]=='u'&&s[i+3]=='i')
			{
				printf("yes");
				return 0;
			}
		}	
	}

	printf("no");	
	return 0;
}