#include <cstdio>
#include <memory.h>
#include <queue>
#include <malloc.h>
#include <cstring>

using namespace std;
int sz,hd=1,nxt[50005][26],fail[50005],id[50005],n,dis[1005];
char s[2000005],sp[1005][55];

void trie_clean()
{
    sz=1;
    memset(nxt,0,sizeof(nxt));
    memset(fail,0,sizeof(fail));
    memset(id,0,sizeof(id));
}

void trie_insert(int head,char s[],int len,int idx)
{
    int p=head;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'A';
        if(!nxt[p][c]) nxt[p][c]=++sz;
        p=nxt[p][c];
    }
    id[p]=idx;
}

void acatm_build(int head)
{
    int p,tp;
    queue<int> q;
    q.push(head);
    fail[head]=0;
    while(!q.empty())
    {
        p=q.front();
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
        int c=(int)s[i]-'A';
        if(c<0||c>=26) {p=head;continue;}
        p=nxt[p][c];
        for(int tp=p;tp;tp=fail[tp])
            dis[id[tp]]++;
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        memset(dis,0,sizeof(dis));
        trie_clean();
        for(int i=0;i<n;i++)
        { 
            scanf("%s",sp[i]);
            trie_insert(hd,sp[i],strlen(sp[i]),i+1);
        }
        acatm_build(hd);
        scanf("%s",s);
        acatm_match(hd,s,strlen(s));
        for(int i=0;i<n;i++)
            if(dis[i+1]) printf("%s: %d\n",sp[i],dis[i+1]);
    }
    return 0;
}