#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;
int seg[MAXN<<2],tag[MAXN<<2],b,n,flag,ans;

inline void pushup(int rt) {seg[rt]=seg[rt<<1]+seg[rt<<1|1];}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        seg[rt]=0;
        return;
    }
    int m=l+r>>1;
    if(l<=m) build(rt<<1,l,m);
    if(m<r) build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify2(int rt,int l,int r,int x,int y,int inf)
{
    if(l==r)
    {
        seg[rt]=y;
        if(y) tag[rt]=inf;
        return;
    }
    int m=l+r>>1;
    if(x<=m) modify2(rt<<1,l,m,x,y,inf);
    else modify2(rt<<1|1,m+1,r,x,y,inf);
    pushup(rt);
}

void modify1(int rt,int l,int r,int L,int R,int LL)
{
    if(l==r)
    {
        if(tag[rt]>=LL)
        {
            ans++;
            seg[rt]=0;
        }
        else
            flag=1;
        return;
    }
    int m=l+r>>1;
    if(seg[rt<<1|1]&&m<R) modify1(rt<<1|1,m+1,r,L,R,LL);
    if(flag)
    {
        pushup(rt);
        return;
    }
    if(seg[rt<<1]&&L<=m) modify1(rt<<1,l,m,L,R,LL);
    pushup(rt);
}

int main()
{
    b=0;
    scanf("%d",&n);
    build(1,1,100000);
    for(int i=0;i<n;i++)
    {
        char op[100];int l,r;
        flag=0,ans=0;
        scanf("%s",op);
        if(op[0]=='A')
        {
            scanf("%d%d",&l,&r);
            modify1(1,1,100000,1,r,l);
            b-=ans-1;
            printf("%d\n",ans);
            modify2(1,1,100000,l,1,r);
        }
        else
            printf("%d\n",b);
    }
    return 0;
}
