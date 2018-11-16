#include <cstdio>
#include <cstring>

const int MAXN=5e5,mod=20071027;
int sz,len,n;
long long dp[300005];
char s[300005];
struct node
{
	int v,ch[26];
}trie[MAXN];

void insert(char *s)
{
	int u=0,l=strlen(s);
	for(int i=0;i<l;i++)
	{
		int c=s[i]-'a';
		if(!trie[u].ch[c])
		{
			sz++;
			memset(&trie[sz],0,sizeof(node));
			trie[u].ch[c]=sz;
		}
		u=trie[u].ch[c];
	}
	trie[u].v++;
}

void find(int k,char *s)
{
	int u=0,l=strlen(s);
	for(int i=0;i<l;i++)
	{
		int c=s[i]-'a';
		if(trie[u].ch[c])
		{
			if(trie[trie[u].ch[c]].v)
				dp[k]=(dp[k]+dp[k+i+1])%mod;
			u=trie[u].ch[c];
		}
		else
			break;
	}
}

int main()
{
	int t=0;
	while(~scanf("%s",&s))
	{
		t++;
		sz=0;
		memset(&trie[0],0,sizeof(node));
		len=strlen(s);
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			char wd[105];
			scanf("%s",wd);
			insert(wd);
		}
		dp[len]=1;
		for(int i=len-1;i>=0;i--)
		{
			dp[i]=0;
			find(i,&s[i]);
		}
		printf("Case %d: %lld\n",t,dp[0]);
	}
	return 0;
}