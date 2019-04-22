#include <cstdio>
#include <memory.h>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN=7e5+5;
int hd,sz,nxt[MAXN][26],fail[MAXN],n,vis[MAXN][2],op[100005],last[100005],lens[100005],id1[MAXN],id2[MAXN];
char s[100005],sm[100005][10];

void clear()
{
    hd=sz=1;
    fail[hd]=0;
    memset(nxt,0,sizeof(nxt));
    memset(fail,0,sizeof(fail));
    memset(last,0xc0,sizeof(last));
    memset(vis,0,sizeof(vis));
    memset(id1,-1,sizeof(id1));
    memset(id2,-1,sizeof(id2));
}

void trie_insert(int head,char s[],int len,int op,int idx)
{
    int p=head;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'a';
        if(!nxt[p][c]) nxt[p][c]=++sz;
        p=nxt[p][c];
    }
    if(!op) id1[p]=idx; else id2[p]=idx;
}

void acatm_build(int head)
{
    queue<int> q;
    q.push(head);
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0;i<26;i++)
            if(nxt[p][i])
            {
                fail[nxt[p][i]]=p==head?head:nxt[fail[p]][i];
                q.push(nxt[p][i]);
            }
            else
                nxt[p][i]=p==head?head:nxt[fail[p]][i];
    }
}

void acatm_match(int head,char s[],int len)
{
    int p=head;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'a';
        p=nxt[p][c];
        for(int tp=p;tp;tp=fail[tp])
            if(~id1[tp]) vis[tp][0]++;
        for(int tp=p;tp;tp=fail[tp])
            if(~id2[tp]&&last[id2[tp]]+lens[id2[tp]]<=i) last[id2[tp]]=i,vis[tp][1]++;
    }
}

int get_ans(int head,char s[],int len,int op)
{
    int p=head;
    for(int i=0;i<len;i++)
        p=nxt[p][s[i]-'a'];
    return vis[p][op];
}

void solve(int cs)
{
    clear();
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %s",&op[i],sm[i]);
        lens[i]=strlen(sm[i]);
        trie_insert(hd,sm[i],lens[i],op[i],i);
    }
    acatm_build(hd);
    acatm_match(hd,s,strlen(s));
    printf("Case %d\n",cs);
    for(int i=0;i<n;i++)
        printf("%d\n",get_ans(hd,sm[i],lens[i],op[i]));
    printf("\n");
}

int main()
{
    //freopen("ZOJ3228.in","r",stdin);
    //freopen("ZOJ3228.out","w",stdout);
    int cs=0;
    while(~scanf("%s",s))
        solve(++cs);
    return 0;
}