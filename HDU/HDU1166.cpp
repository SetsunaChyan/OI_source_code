#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=50005;
int seg[MAXN<<2],a[MAXN],n,x,y;
char op[10];

void pushup(int rt)
{
    seg[rt]=seg[rt<<1]+seg[rt<<1|1];
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        seg[rt]=a[l];
        return;
    }
    int m=(l+r)>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify(int rt,int l,int r,int x,int y)
{
    if(l==r)
    {
        seg[rt]+=y;
        return;
    }
    int m=(l+r)>>1;
    if(x<=m) modify(rt<<1,l,m,x,y);
    else modify(rt<<1|1,m+1,r,x,y);
    pushup(rt);
}

int query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return seg[rt];
    int m=(l+r)>>1,ret=0;
    if(L<=m) ret+=query(rt<<1,l,m,L,R);
    if(R>m) ret+=query(rt<<1|1,m+1,r,L,R);
    return ret;
}

void solve(int cs)
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    printf("Case %d:\n",cs);
    while(1)
    {
        scanf("%s",op);
        if(op[0]=='E') break;
        scanf("%d%d",&x,&y);
        if(op[0]=='Q') printf("%d\n",query(1,1,n,x,y));
        else if(op[0]=='A') modify(1,1,n,x,y);
        else if(op[0]=='S') modify(1,1,n,x,-y);
    }
}

int main()
{
    int _;
    scanf("%d",&_);
    for(int i=1;i<=_;i++) solve(i);
    return 0;
}