#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=200005;
int n;
ll seg[MAXN<<2],lazy[MAXN<<2],sum,len[MAXN<<1];
struct edge
{
    ll y1,y2,x;
}e[MAXN];

bool cmp(edge a,edge b){return a.x<b.x;}
int _find(double x){return lower_bound(len,len+n,x)-len+1;}

inline ll getlen(int l,int r)
{
    return len[r]-len[l-1];
}

inline void pushdown(int rt,int l,int r)
{
    if(lazy[rt]==0) return;
    lazy[rt<<1]^=1,lazy[rt<<1|1]^=1;
    int mid=l+r>>1;
    seg[rt<<1]=getlen(l,mid)-seg[rt<<1];
    seg[rt<<1|1]=getlen(mid+1,r)-seg[rt<<1|1];
    lazy[rt]=0;
}

void modify(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)
    {
        seg[rt]=getlen(l,r)-seg[rt];
        lazy[rt]^=1;
        return;
    }
    pushdown(rt,l,r);
    int m=l+r>>1;
    if(L<=m) modify(rt<<1,l,m,L,R);
    if(m<R) modify(rt<<1|1,m+1,r,L,R);
    seg[rt]=seg[rt<<1]+seg[rt<<1|1];
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        ll x1,y1,x2,y2;
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        len[i<<1]=y1,len[i<<1|1]=y2;
        e[i<<1].y1=e[i<<1|1].y1=y1;
        e[i<<1].y2=e[i<<1|1].y2=y2;
        e[i<<1].x=x1,e[i<<1|1].x=x2;
    }
    n<<=1,sum=0;
    sort(len,len+n);
    sort(e,e+n,cmp);
    modify(1,1,n,_find(e[0].y1),_find(e[0].y2)-1);
    for(int i=1;i<n;i++)
    {
        sum+=seg[1]*(e[i].x-e[i-1].x);
        modify(1,1,n,_find(e[i].y1),_find(e[i].y2)-1);
    }
    printf("%lld",sum);
    return 0;
}
