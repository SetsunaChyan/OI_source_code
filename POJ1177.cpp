#include <bits/stdc++.h>
using namespace std;

inline void pushup(int rt,int l,int r)
{
    if(cover[rt]) seg[rt]=1;
    else if(l==r) seg[rt]=0; else seg[rt]=
}

void build(int rt,int l,int r)
{
    cover[rt]=0;
    if(l==r)
    {
        seg[rt]=0;
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
        pushup(rt,l,r);
        return;
    }
    int m=l+r>>1;

}

int main()
{


    return 0;
}
