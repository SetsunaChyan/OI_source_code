#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum;
int n,m,a[100005],pos[100005];

namespace seg
{
    int tot,root[100005],cnt[100005*160],lc[100005*160],rc[100005*160];
    void modify(int &rt,int l,int r,int x,int y)
    {
        if(!rt) rt=++tot;
        cnt[rt]+=y;
        if(l==r) return;
        int m=l+r>>1;
        if(x<=m) modify(lc[rt],l,m,x,y);
        else modify(rc[rt],m+1,r,x,y);
    }
    int query(int rt,int l,int r,int L,int R)
    {
        if(rt==0||l>R||r<L) return 0;
        if(L<=l&&r<=R) return cnt[rt];
        int m=l+r>>1;
        return query(lc[rt],l,m,L,R)+query(rc[rt],m+1,r,L,R);
    }
}

namespace bit
{
    void add(int pos,int x,int y)
    {
        for(;pos<=n;pos+=pos&-pos) seg::modify(seg::root[pos],1,n,x,y);
    }
    int sum(int l,int r,int L,int R)
    {
        if(L<=0||R>n||R<L) return 0;
        int ret=0;
        for(int i=l-1;i;i-=i&-i) ret-=seg::query(seg::root[i],1,n,L,R);
        for(int i=r;i;i-=i&-i) ret+=seg::query(seg::root[i],1,n,L,R);
        return ret;
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        bit::add(i,a[i],1),pos[a[i]]=i;
    }
    for(int i=n-1;i>=1;i--)
        sum+=bit::sum(i+1,n,1,a[i]-1);
    for(int i=0;i<m;i++)
    {
        int x;
        scanf("%d",&x);
        printf("%lld\n",sum);
        sum-=bit::sum(pos[x],n,1,x-1)+bit::sum(1,pos[x],x+1,n);
        bit::add(pos[x],x,-1);
    }
    return 0;
}
