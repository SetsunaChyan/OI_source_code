#include <bits/stdc++.h>
using namespace std;

int n,m,hd,sz,nxt[100005][2],fail[100005],id[100005],idl[100005],vis[100005],ploc[15],loc,dp[15][1<<12],dis[15][15];
char s[1005];

void clear()
{
    memset(nxt,0,sizeof(nxt));
    memset(fail,0,sizeof(fail));
    memset(id,0,sizeof(id));
    memset(dp,0x3f,sizeof(dp));
    memset(dis,0x3f,sizeof(dis));
    memset(idl,-1,sizeof(idl));
    hd=sz=1,dp[0][0]=0;
    loc=1,ploc[0]=1,idl[1]=0;
}

void trie_insert(int head,char s[],int len,int idx)
{
    int p=head;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'0';
        if(!nxt[p][c]) nxt[p][c]=++sz;
        p=nxt[p][c];
    }
    id[p]|=idx;
    idl[p]=loc;
    if(~idx) ploc[loc++]=p; 
}

void acatm_build(int head)
{
    queue<int> q;
    q.push(head);
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0;i<2;i++)
            if(nxt[p][i])
            {
                fail[nxt[p][i]]=head==p?head:nxt[fail[p]][i];
                id[nxt[p][i]]|=id[fail[nxt[p][i]]];
                q.push(nxt[p][i]);
            }
            else
                nxt[p][i]=head==p?head:nxt[fail[p]][i];
    }
}

void bfs(int x)
{
    memset(vis,0,sizeof(vis));
    vis[ploc[x]]=1;
    queue<pair<int,int> > q;
    q.push(make_pair(ploc[x],0));
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        if(~idl[p.first]) dis[x][idl[p.first]]=p.second;
        for(int i=0;i<2;i++)
            if(!vis[nxt[p.first][i]]&&~id[nxt[p.first][i]])
            {
                q.push(make_pair(nxt[p.first][i],p.second+1));
                vis[nxt[p.first][i]]=1;
            }
    }
}

void solve()
{
    clear();
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        trie_insert(hd,s,strlen(s),1<<i);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%s",s);
        trie_insert(hd,s,strlen(s),-1);
    }
    acatm_build(hd);
    for(int i=0;i<loc;i++) bfs(i);
    for(int j=0;j<(1<<n);j++)
        for(int i=0;i<loc;i++)
            for(int k=0;k<loc;k++)
                dp[k][j|id[ploc[k]]]=min(dp[k][j|id[ploc[k]]],dp[i][j]+dis[i][k]);
    int ans=0x3f3f3f3f;
    for(int i=0;i<loc;i++)
        ans=min(ans,dp[i][(1<<n)-1]);
    printf("%d\n",ans);
}

int main()
{
    while(~scanf("%d%d",&n,&m)&&n&&m)
        solve();
    return 0;
}