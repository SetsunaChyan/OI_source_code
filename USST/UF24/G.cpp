#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int hd,sz,nxt[6400005][2],cnt[6400005],n,tot;
ll a[100005],suf[100005],pre[100005],ans;

void clear()
{
    hd=sz=1;
    memset(nxt,0,sizeof(nxt));
    memset(cnt,0,sizeof(cnt));
}

void trie_insert(int head,ll x)
{
    int tmp[64],p=head;
    tot++;
    for(int i=63;i>=0;i--) tmp[i]=x&1,x>>=1;
    for(int i=0;i<64;i++)
    {
        if(!nxt[p][tmp[i]]) nxt[p][tmp[i]]=++sz;
        p=nxt[p][tmp[i]];
        cnt[p]++;
    }
}

ll trie_query(int head,ll x)
{
    int tmp[64],p=head;
    ll ret=0,qaq=x,k=tot;
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

void trie_del(int head,ll x)
{
    tot--;
    int tmp[64],p=head;
    for(int i=63;i>=0;i--) tmp[i]=x&1,x>>=1;
    for(int i=0;i<64;i++)
    {
        if(!nxt[p][tmp[i]]) nxt[p][tmp[i]]=++sz;
        p=nxt[p][tmp[i]];
        cnt[p]--;
    }
}

int main()
{
    clear();
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",a+i);
    ans=a[0];
    for(int i=n-1;i>=0;i--)
        suf[i]=suf[i+1]^a[i],trie_insert(hd,suf[i]),ans=max(ans,suf[i]);
    pre[0]=a[0];
    for(int i=1;i<n;i++) pre[i]=pre[i-1]^a[i],ans=max(ans,pre[i]);
    for(int i=0;i<n;i++)
    {
        trie_del(hd,suf[i]);
        ans=max(ans,trie_query(hd,pre[i]));
    }
    printf("%lld",ans);
    return 0;
}
