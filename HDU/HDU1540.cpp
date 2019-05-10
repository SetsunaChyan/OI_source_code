#include <bits/stdc++.h>
using namespace std;

const int MAXN=50005;
int pre[MAXN<<2],suf[MAXN<<2],n,m;
stack<int> s;

inline void pushup(int rt,int lenl,int lenr)
{
    pre[rt]=pre[rt<<1];
    if(pre[rt<<1]==lenl) pre[rt]+=pre[rt<<1|1];
    suf[rt]=suf[rt<<1|1];
    if(suf[rt<<1|1]==lenr) suf[rt]+=suf[rt<<1];
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        pre[rt]=suf[rt]=1;
        return;
    }
    int m=l+r>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
    pushup(rt,m-l+1,r-m);
}

void modify(int rt,int l,int r,int x,int y)
{
    if(l==r)
    {
        pre[rt]=suf[rt]=y;
        return;
    }
    int m=l+r>>1;
    if(x<=m) modify(rt<<1,l,m,x,y);
    else modify(rt<<1|1,m+1,r,x,y);
    pushup(rt,m-l+1,r-m);
}

int query(int rt,int l,int r,int x)
{
    if(l==r) return pre[rt];
    int m=l+r>>1;
    if(x<=m&&m+1-suf[rt<<1]>x) return query(rt<<1,l,m,x);
    if(x>m&&m+pre[rt<<1|1]<x) return query(rt<<1|1,m+1,r,x);
    return suf[rt<<1]+pre[rt<<1|1];
}

void solve()
{
    while(!s.empty()) s.pop();
    build(1,1,n);
    while(m--)
    {
        char op;
        int x;
        scanf(" %c",&op);
        if(op!='R') scanf("%d",&x);
        if(op=='D') {modify(1,1,n,x,0);s.push(x);}
        else if(op=='Q') printf("%d\n",query(1,1,n,x));
        else if(!s.empty()) {modify(1,1,n,s.top(),1);s.pop();}
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m)) solve();
    return 0;
}