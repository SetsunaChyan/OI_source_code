#include <cstdio>
#include <memory.h>
#include <cstring>
#include <malloc.h>
#include <queue>
#include <algorithm>

using namespace std;

const int LIMIT=128;
int sz=1,webtot=0,tot,bd[5],n,m,ch[100005][LIMIT],id[100005],fail[100005],head=1,vis[505];
char s[10005];

inline int trie_add(int x,int y,int z)
{
    ch[x][y]=++sz;
    return sz;
}

void trie_insert(int head,char s[],int len,int idx)
{
    int p=head;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-0x20;
        if(!ch[p][c]) 
        {
            ch[p][c]=++sz;
            memset(ch[sz],0,sizeof(ch[sz]));
        }
        p=ch[p][c];
    }
    id[p]=idx;
}

void acatm_build(int head)
{
    int p,tp;
    queue<int> q;
    fail[head]=0;
    q.push(head);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(int i=0;i<LIMIT;i++)
            if(ch[p][i])
            {
                tp=fail[p];
                while(tp&&!ch[tp][i]) tp=fail[tp];
                fail[ch[p][i]]=tp?ch[tp][i]:head;
                q.push(ch[p][i]);
            }
    }
}

void acatm_match(int head,char s[],int len)
{
    int p=head,tp;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-0x20;
        while(p!=head&&!ch[p][c]) p=fail[p];
        if(ch[p][c])
        {
            p=ch[p][c];
            if(id[p])
            {
                tp=p;
                while(tp)
                {
                    if(id[tp]&&!vis[id[tp]])
                    {
                        bd[tot++]=id[tp];
                        vis[id[tp]]=1;
                        if(tot>=3) return;
                    }
                    tp=fail[tp];
                }
            }
        }
    }
}

int main()
{
    memset(ch[1],0,sizeof(ch[1]));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        trie_insert(head,s,strlen(s),i+1);
    }
    acatm_build(head);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        tot=0;
        scanf("%s",s);
        memset(vis,0,sizeof(vis));
        acatm_match(head,s,strlen(s));
        if(tot)
        {
            sort(bd,bd+tot);
            printf("web %d:",i+1);
            for(int j=0;j<tot;j++)
                printf(" %d",bd[j]);
            webtot++;
            printf("\n");
        }
    }
    printf("total: %d\n",webtot);
    return 0;
}