#include <bits/stdc++.h>
using namespace std;

const int MAXN=205;
int n,cover[MAXN<<2];
double seg[MAXN<<2],sum=0,len[MAXN<<1];
struct edge
{
    double y1,y2,x;
    int val;
}e[MAXN];

bool cmp(edge a,edge b){return a.x<b.x;}
int _find(double x){return lower_bound(len,len+n,x)-len+1;}

void pushup(int rt,int l,int r)
{
    if(cover[rt]) seg[rt]=len[r]-len[l-1];
    else seg[rt]=seg[rt<<1]+seg[rt<<1|1];
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        seg[rt]=cover[rt]=0;
        return;
    }
    int m=l+r>>1;
    if(l<=m) build(rt<<1,l,m);
    if(m<r) build(rt<<1|1,m+1,r);
    pushup(rt,l,r);
}

void modify(int rt,int l,int r,int L,int R,int x)
{
    if(L<=l&&r<=R)
    {
        cover[rt]+=x;
        if(cover[rt]) seg[rt]=len[r]-len[l-1];
        else seg[rt]=seg[rt<<1]+seg[rt<<1|1];
        return;
    }
    int m=l+r>>1;
    if(L<=m) modify(rt<<1,l,m,L,R,x);
    if(m<R) modify(rt<<1|1,m+1,r,L,R,x);
    pushup(rt,l,r);
}

void solve(int cs)
{
    for(int i=0;i<n;i++)
    {
        double x1,y1,x2,y2;
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        len[i<<1]=y1,len[i<<1|1]=y2;
        e[i<<1].y1=e[i<<1|1].y1=y1;
        e[i<<1].y2=e[i<<1|1].y2=y2;
        e[i<<1].x=x1,e[i<<1|1].x=x2;
        e[i<<1].val=1,e[i<<1|1].val=-1;
    }
    n<<=1,sum=0;
    sort(len,len+n);
    sort(e,e+n,cmp);
    build(1,1,n);
    modify(1,1,n,_find(e[0].y1),_find(e[0].y2)-1,e[0].val);
    for(int i=1;i<n;i++)
    {
        sum+=seg[1]*(e[i].x-e[i-1].x);
        modify(1,1,n,_find(e[i].y1),_find(e[i].y2)-1,e[i].val);
    }
    printf("Test case #%d\nTotal explored area: %.2f\n\n",cs,sum);
}

int main()
{
    int _=0;
    while(~scanf("%d",&n)&&n) solve(++_);
    return 0;
}
