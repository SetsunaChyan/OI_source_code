#include <cstdio>
#include <memory.h>
#include <cstring>

struct node
{
    node *nxt[26],*fail;
    int id;
    node()
    {
        memset(nxt,0,sizeof(nxt));
        fail=NULL;
        id=0;
    }
}*trie;

void del_trie(node *p)
{
    if(p==NULL) return;
    for(int i=0;i<26;i++)
        del_trie(p->nxt[i]);
    free(p);
    p=NULL;
}

int main()
{

    return 0;
}