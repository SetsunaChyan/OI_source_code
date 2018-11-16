#include <cstdio>
#include <cstring>

const int MAXN=100050;
char s[MAXN],c[MAXN];
int head,cnt,end,st,cur,nxt[MAXN];

int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	while(scanf("%s",s)!=EOF)
	{
		head=0;cnt=0;end=0;st=1;cur=0;
		int i=0,l=strlen(s);
		nxt[0]=1;
		while(i<l&&s[i]=='['||s[i]==']')i++;
		for(;i<l;i++)
		{ 
			if(s[i]=='[')
			{
				st=0;
				cur=0;
			}
			else if(s[i]==']')
			{
				st=1;
				cur=end;
			}
			else
			{
				cnt++;
				c[cnt]=s[i];
				nxt[cnt]=nxt[cur];
				nxt[cur]=cnt;

				cur=cnt;
				if(st==1) end=cnt;
			}
		}
		for(int i=1,j=nxt[0];i<=cnt;i++,j=nxt[j])
			printf("%c",c[j]);
		printf("\n");
	}
	
	return 0;
}