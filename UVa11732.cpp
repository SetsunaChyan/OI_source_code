#include <cstdio>
#include <cstring>

struct node
{
	int next,right;
	long long val;
	char c;
}trie[4005000];
int n,next;
long long ans;
char s[1050];

void insert(char *s)
{
	int u=0,l=strlen(s)+1;
	for(int i=0;i<l;i++)
	{
		int flag=0,v;
		for(v=trie[u].next;v!=-1;v=trie[v].right)
		{
			if(s[i]==trie[v].c)
			{
				flag=v;
				ans+=2*trie[v].val;
			}
			else
				ans+=trie[v].val;
		}
		if(!flag)
		{
			v=next++;
			trie[v].right=trie[u].next;
			trie[u].next=v;
			trie[v].next=-1;
			trie[v].val=0;
			trie[v].c=s[i];
		}
		if(flag) u=flag; else u=v;
		trie[u].val++;
	}
}

int main()
{
	int t=0;
	while(scanf("%d",&n),n)
	{
		t++;
		trie[0].next=-1;
		trie[0].right=-1;
		trie[0].val=0;
		ans=0;
		next=1;
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			insert(s);
		}
		printf("Case %d: %lld\n",t,ans);
	}
	
	return 0;
}