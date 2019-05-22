#include <bits/stdc++.h>
using namespace std;

int n,nxt[30005][2],fail[30005],cnt[30005],hd=1,sz=1,vis[30005],flag=0;
char s[30005];

void trie_insert(int head,char s[],int len)
{
    int p=head;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'0';
        if(!nxt[p][c]) nxt[p][c]=++sz;
        p=nxt[p][c];
    }
    cnt[p]=1;
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
                cnt[nxt[p][i]]|=cnt[fail[nxt[p][i]]];
                q.push(nxt[p][i]);
            }
            else 
                nxt[p][i]=head==p?head:nxt[fail[p]][i];
    }
}

void dfs(int p)
{
    vis[p]=1;
    for(int i=0;i<2;i++)
    {
        if(cnt[nxt[p][i]]) continue;
        if(vis[nxt[p][i]]) flag=1;
        if(flag) return;
        dfs(nxt[p][i]);
    }
    vis[p]=0;
}

int main()
{
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    memset(nxt,0,sizeof(nxt));
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        trie_insert(hd,s,strlen(s));
    }
    acatm_build(hd);
    dfs(hd);
    if(flag) printf("TAK"); else printf("NIE");
    return 0;
}