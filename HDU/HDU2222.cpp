#include <cstdio>
#include <memory.h>
#include <malloc.h>
#include <cstring>
#include <queue>

using namespace std;

int n;
char stmp[10005],s[1000005];
struct node
{
    node *nxt[26],*fail;
    int cnt;
    node()
    {
        memset(nxt,0,sizeof(nxt));
        fail=NULL;
        cnt=0;
    }
}*trie;
queue<node *> q;

void trie_del(node *p)
{
    if(p==NULL) return;
    for(int i=0;i<26;i++)
        trie_del(p->nxt[i]);
    free(p);
    p=NULL;
}

void trie_insert(node *head,char s[],int len,int delta)
{
    node *p=head;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'a';
        if(p->nxt[c]==NULL)
            p->nxt[c]=new node();
        p=p->nxt[c];
    }
    p->cnt+=delta;
}

void acatm_build(node *head)
{
    head->fail=NULL;
    q.push(head);
    while(!q.empty())
    {
        node *p=q.front();
        q.pop();
        for(int i=0;i<26;i++)
            if(p->nxt[i])
            {
                node *tp=p->fail;
                while(tp&&tp->nxt[i]==0) tp=tp->fail;
                p->nxt[i]->fail=tp?tp->nxt[i]:head;
                q.push(p->nxt[i]);
            }
            //else
            //    p->nxt[i]=(p!=head)?(p->fail)->nxt[i]:head;
    }
}

int acatm_match(node *head,char s[],int len)
{
    int ret=0;
    node *p=head;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'a';
        while(p->nxt[c]==NULL&&p->fail) p=p->fail; 
        if(p->nxt[c]) 
        {
            p=p->nxt[c];
            node *tp=p;
            while(tp->fail)
            {
                ret+=tp->cnt;
                tp->cnt=0;
                tp=tp->fail;
            }
        }
    }
    return ret;
}

void solve()
{
    trie_del(trie);
    trie=new node();
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",stmp);
        trie_insert(trie,stmp,strlen(stmp),1);
    }
    acatm_build(trie);
    scanf("%s",s);
    printf("%d\n",acatm_match(trie,s,strlen(s)));
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
        solve();
    return 0;
}