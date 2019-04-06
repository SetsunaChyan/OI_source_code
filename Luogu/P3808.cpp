#include <cstdio>
#include <memory.h>
#include <queue>
#include <malloc.h>
#include <cstring>

using namespace std;
int sz,hd=1,nxt[1000005][26],fail[1000005],id[1000005],n;
char s[1000005];

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
        int c=s[i]-'a';
        if(!nxt[p][c]) nxt[p][c]=++sz;
        p=nxt[p][c];
    }
    id[p]+=idx;
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

int acatm_match(int head,char s[],int len)
{
    int p=head,ret=0;
    for(int i=0;i<len;i++)
    {
        int c=(int)s[i]-'a';
        p=nxt[p][c];
        for(int tp=p;tp&&id[tp]!=-1;tp=fail[tp])
        {
            if(id[tp]) ret+=id[tp];
            id[tp]=-1;
        }
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    trie_clean();
    for(int i=0;i<n;i++)
    { 
        scanf("%s",s);
        trie_insert(hd,s,strlen(s),1);
    }
    acatm_build(hd);
    scanf("%s",s);
    printf("%d",acatm_match(hd,s,strlen(s)));
    return 0;
}