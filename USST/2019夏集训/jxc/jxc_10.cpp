#include <bits/stdc++.h>
using namespace std;

const int MAXN=105;
int l,sz=1,tot=0,ans,nxt[MAXN*MAXN][4],id[MAXN*MAXN],fail[MAXN*MAXN],len[MAXN*MAXN],vis[MAXN*MAXN],last[MAXN*MAXN];
char s[MAXN];

inline int getid(char c)//NEWS
{
    if(c=='N') return 0;
    if(c=='E') return 1;
    if(c=='W') return 2;
    return 3;
}

void trie_insert(char s[],int l,int num)
{
    int p=1;
    for(int i=0;i<l;i++)
    {
        int c=getid(s[i]);
        if(!nxt[p][c]) nxt[p][c]=++sz;
        p=nxt[p][c];
    }
    id[p]=num;
}

void build()
{
    queue<int> q;
    fail[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0;i<4;i++)
            if(nxt[p][i])
            {
                fail[nxt[p][i]]=p==1?1:nxt[fail[p]][i];
                q.push(nxt[p][i]);
            }
            else
                nxt[p][i]=p==1?1:nxt[fail[p]][i];
    }
}

void match(char s[],int l)
{
    int p=1;
    for(int i=0;i<l;i++)
    {
        int c=getid(s[i]);
        p=nxt[p][c];
        for(int tp=p;tp;tp=fail[tp])
            if(id[tp]&&last[id[tp]]+len[id[tp]]<=i)
                last[id[tp]]=i,vis[id[tp]]++;
    }
}

int main()
{
    memset(last,0xc0,sizeof(last));
    memset(vis,0,sizeof(vis));
    memset(nxt,0,sizeof(nxt));
    scanf("%s",s);
    ans=l=strlen(s);
    for(int i=2;i<=l/2;i++)
        for(int j=0;j+i-1<l;j++)
            trie_insert(s+j,i,++tot),len[tot]=i;
    build();
    match(s,l);
    for(int i=1;i<=tot;i++)
        ans=min(ans,l+len[i]-len[i]*vis[i]+vis[i]);
    printf("%d",ans);
    return 0;
}
