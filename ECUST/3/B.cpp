#include <cstdio>
#include <cstring>
char s[1000],c;

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		while(1)
		{
			scanf("%s%c",s,&c);
			int l=strlen(s);
			for(int i=0;i<l;i++)
				if('A'<=s[i]&&s[i]<='Z')
					s[i]=s[i]-'A'+'a';
			s[0]=s[0]-'a'+'A';
			if(c==' ')
				printf("%c. ",s[0]);
			else
			{
				printf("%s\n",s);
				break;
			}
		}
	} 
	return 0;
}
