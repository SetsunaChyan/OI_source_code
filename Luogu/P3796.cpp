#include <cstdio>
#include <cstring>
#include <queue>
#include <memory.h>

using namespace std;

int vis[155],sz,hd=1,fail[12000],nxt[12000][26],id[12000],cnt[12000],ans,n;
char sp[155][100],s[1000005];

inline int max(int a,int b){return a>b?a:b;}

void trie_clean()
{
    sz=1;
    memset(nxt,0,sizeof(nxt));
    memset(id,0,sizeof(id));
    memset(fail,0,sizeof(fail));
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
}

void trie_insert(int head,char s[],int len,int idx)
{
    int p=head;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'a';
        if(!nxt[p][c]) nxt[p][c]=++sz;
        p=nxt[p][c];
    }
    id[p]=idx;
    cnt[p]++;
}

void acatm_build(int head)
{
    queue<int> q;
    int p,tp;
    q.push(head);
    fail[head]=0;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(int i=0;i<26;i++)
            if(nxt[p][i])
            {
                fail[nxt[p][i]]=head!=p?nxt[fail[p]][i]:head;
                q.push(nxt[p][i]);
            }
            else
                nxt[p][i]=head!=p?nxt[fail[p]][i]:head;
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
            vis[id[tp]]+=cnt[tp];
    }
}

int main()
{
    while(~scanf("%d",&n)&&n)
    {
        trie_clean();ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",sp[i]);
            trie_insert(hd,sp[i],strlen(sp[i]),i+1);
        }
        acatm_build(hd);
        scanf("%s",s);
        acatm_match(hd,s,strlen(s));
        for(int i=0;i<n;i++) ans=max(ans,vis[i+1]);
        printf("%d\n",ans);
        for(int i=0;i<n;i++)
            if(vis[i+1]==ans) printf("%s\n",sp[i]);
    }
    return 0;
}