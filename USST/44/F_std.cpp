#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int hd,sz,nxt[640005][2],cnt[640005],m,n;
ll b[10005],c[10005];

void clear()
{
    hd=sz=1;
    memset(nxt,0,sizeof(nxt));
    memset(cnt,0,sizeof(cnt));
}

void trie_insert(int head,ll x)
{
    int tmp[64],p=head;
    for(int i=63;i>=0;i--) tmp[i]=x&1,x>>=1;
    for(int i=0;i<64;i++)
    {
        if(!nxt[p][tmp[i]]) nxt[p][tmp[i]]=++sz;
        p=nxt[p][tmp[i]];
        cnt[p]++;
    }
}

ll trie_query(int head,ll x,ll k)
{
    int tmp[64],p=head;
    ll ret=0,qaq=x;
    for(int i=63;i>=0;i--) tmp[i]=x&1,x>>=1;
    for(int i=0;i<64;i++)
    {
        int q=tmp[i];
        if(cnt[nxt[p][q]]>=k)
            p=nxt[p][q],ret=(ret<<1)+q;
        else
            k=k-cnt[nxt[p][q]],p=nxt[p][1^q],ret=(ret<<1)+(q^1);
    }
    return ret^qaq;
}

int main()
{
    clear();
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) 
    {
        ll x;
        scanf("%lld",&x);
        trie_insert(hd,x);
    }
    for(int i=0;i<m;i++) scanf("%lld",&b[i]);
    for(int i=0;i<m;i++) scanf("%lld",&c[i]);
    for(int i=0;i<m;i++)
        printf("%lld",trie_query(hd,b[i],c[i]));
    return 0;
}