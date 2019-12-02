#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int k1,k2,k3,n,pre1[200005],pre2[200005],pre3[200005],a[200005];
int seg[200005<<2];

void build(int rt,int l,int r)
{
    if(l==r)
    {
        seg[rt]=a[l];
        return;
    }
    int m=l+r>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
    seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
}

int query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return seg[rt];
    int m=l+r>>1,ret=0;
    if(L<=m) ret=max(ret,query(rt<<1,l,m,L,R));
    if(m<R) ret=max(ret,query(rt<<1|1,m+1,r,L,R));
    return ret;
}

int main()
{
    scanf("%d%d%d",&k1,&k2,&k3);
    n=k1+k2+k3;
    for(int i=0,x;i<k1;i++)
        scanf("%d",&x),pre1[x]=1;
    for(int i=0,x;i<k2;i++)
        scanf("%d",&x),pre2[x]=1;
    for(int i=0,x;i<k3;i++)
        scanf("%d",&x),pre3[x]=1;
    for(int i=1;i<=n+1;i++)
        pre1[i]+=pre1[i-1],
        pre2[i]+=pre2[i-1],
        pre3[i]+=pre3[i-1];
    a[0]=pre3[n+1];
    for(int i=1;i<=n+1;i++)
        a[i]=pre2[i]+pre3[n+1]-pre3[i];
    build(1,1,n+1);
    int ans=0;
    for(int i=1;i<=n+1;i++)
    {
        //printf("[1,%d) %d %d !%d\n",i,pre1[i-1]-pre1[0],query(1,1,n+1,max(1,i-1),n+1)-pre2[i-1],query(1,1,n+1,max(1,i-1),n+1));
        int tmp=pre1[i-1]-pre1[0]+query(1,1,n+1,max(1,i-1),n+1)-pre2[i-1];
        if(i==1) tmp=max(tmp,pre1[i-1]-pre1[0]+a[0]);
        ans=max(tmp,ans);
    }
    ans=n-ans;
    printf("%d",ans);
    return 0;
}
