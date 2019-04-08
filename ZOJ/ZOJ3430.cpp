#include <cstdio>
#include <memory.h>
#include <cstring>
#include <queue>

using namespace std;

int n,m,sz,hd=1,nxt[40005][256],fail[40005],cnt[40005],s[40005],len,id[40005],vis[1005];
queue<int> q;
char st[40005];

inline int encode(char x) 
{
    if(x>='A'&&x<='Z') return x-'A';
    if(x>='a'&&x<='z') return x-'a'+26;
    if(x>='0'&&x<='9') return x-'0'+52;
    if(x=='+') return 62;
    if(x=='/') return 63; 
    return -1;
}

void trans(int s[],char sc[])
{
    int tot=0,l=strlen(sc),j=0;
    for(int i=0;i<l;i++)
    {
        int t=encode(sc[i]);
        if(t==-1)
        {
            tot-=2;
            continue;
        }
        for(int j=5;j>=0;j--)
        {
            s[tot+j]=(t&1);
            t>>=1;
        }
        tot+=6;
    }
    for(j=0;j*8<tot;j++)
    {
        int tmp=0;
        for(int k=0;k<8;k++) tmp=(tmp<<1)+s[8*j+k];
        s[j]=tmp;
    }
    len=j;
}

void trie_clean()
{
    sz=1;
    memset(id,0,sizeof(id));
    memset(nxt,0,sizeof(nxt));
    memset(fail,0,sizeof(fail));
    memset(cnt,0,sizeof(cnt));
}

void trie_insert(int head,int s[],int len,int idx)
{
    int p=head;
    for(int i=0;i<len;i++)
    {
        int c=s[i];
        if(!nxt[p][c]) nxt[p][c]=++sz;
        p=nxt[p][c];
    }
    id[p]=idx;
    cnt[p]++;
}

void acatm_build(int head)
{
    int p;
    q.push(head);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(int i=0;i<256;i++)
            if(nxt[p][i])
            {
                fail[nxt[p][i]]=head==p?head:nxt[fail[p]][i];
                q.push(nxt[p][i]);
            }
            else
                nxt[p][i]=head==p?head:nxt[fail[p]][i];
    }
}

int acatm_match(int head,int s[],int len)
{
    int p=head,ret=0;
    for(int i=0;i<len;i++)
    {
        int c=s[i];
        p=nxt[p][c];
        for(int tp=p;tp;tp=fail[tp])
        {
            if(!vis[id[tp]]) ret+=cnt[tp];
            vis[id[tp]]=1;
        }
    }
    return ret;
}

int main()
{
    //freopen("out.txt","w",stdout);
    while(~scanf("%d",&n)&&n)
    {
        trie_clean();
        for(int i=0;i<n;i++)
        {
            scanf("%s",st);
            trans(s,st);
            trie_insert(hd,s,len,i+1);
        }
        acatm_build(hd);
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            memset(vis,0,sizeof(vis));
            scanf("%s",st);
            trans(s,st);
            printf("%d\n",acatm_match(hd,s,len));
        }
        printf("\n");
    }
    return 0;
}