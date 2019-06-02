#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[105];
ll f[105],nxt[1000005][26],cnt[1000005],ed[1000005];
int n,m,sz=1;

void trie_insert(char s[])
{
    int l=strlen(s),p=1;
    for(int i=0;i<l;i++)
    {
        int c=s[i]-'A';
        if(!nxt[p][c]) nxt[p][c]=++sz;
        p=nxt[p][c];
        cnt[p]++;
    }
    ed[p]++;
}

void dfs(int now,int dep)
{
    f[dep]+=ed[now]*ed[now];
    for(int i=0;i<26;i++)
        if(nxt[now][i]) 
        {
            f[dep]+=cnt[nxt[now][i]]*(cnt[now]-cnt[nxt[now][i]]);
            dfs(nxt[now][i],dep+1);
        }
}

int main()
{
    memset(nxt,0,sizeof(nxt));
    memset(ed,0,sizeof(ed));
    memset(cnt,0,sizeof(cnt));
    memset(f,0,sizeof(f));
    scanf("%d%d",&n,&m);
    while(n--)
    {
        scanf("%s",s);
        trie_insert(s);
    }
    dfs(1,0);
    for(int i=1;i<=100;i++) 
        f[i]+=f[i-1];
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%lld\n",f[r]-f[l-1]);
    }
    return 0;
}