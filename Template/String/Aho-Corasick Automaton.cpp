#include <cstdio>
#include <memory.h>
#include <malloc.h>
#include <cstring>
#include <queue>

/*
AC自动机
多模式串匹配
这边的trie是动态开点
*/

using namespace std;

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
    queue<node *> q;
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
            if(p->cnt)
            {
                node *tp=p;
                while(tp->fail)
                {
                    ret+=tp->cnt;
                    tp->cnt=0;
                    tp=tp->fail;
                }
            }
        }
    }
    return ret;
}

