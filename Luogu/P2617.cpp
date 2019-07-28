#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;
int n,m,nx,a[MAXN],tmp[MAXN],X[MAXN],Y[MAXN],c1,c2,org[MAXN];
struct SEG
{
    int root[MAXN],lc[MAXN*500],rc[MAXN*500],cnt[MAXN*500],tot;
    void modify(int &rt,int l,int r,int x,int y)
    {
        if(rt==0) rt=++tot;
        cnt[rt]+=y;
        if(l==r) return;
        int m=l+r>>1;
        if(x<=m) modify(lc[rt],l,m,x,y);
        else modify(rc[rt],m+1,r,x,y);
    }
    int query(int l,int r,int k)
    {
        if(l==r) return l;
        int sum=0,m=l+r>>1;
        for(int i=0;i<c1;i++) sum-=cnt[lc[X[i]]];
        for(int i=0;i<c2;i++) sum+=cnt[lc[Y[i]]];
        if(sum>=k)
        {
            for(int i=0;i<c1;i++) X[i]=lc[X[i]];
            for(int i=0;i<c2;i++) Y[i]=lc[Y[i]];
            return query(l,m,k);
        }
        else
        {
            for(int i=0;i<c1;i++) X[i]=rc[X[i]];
            for(int i=0;i<c2;i++) Y[i]=rc[Y[i]];
            return query(m+1,r,k-sum);
        }
    }
}seg;
struct opt
{
    int type,l,r,k;
}op[MAXN];

void add(int pos,int x,int y)
{
    for(;pos<=n;pos+=pos&-pos) seg.modify(seg.root[pos],1,nx,x,y);
}

int query(int l,int r,int k)
{
    c1=c2=0;
    for(int i=l-1;i;i-=i&-i) X[c1++]=seg.root[i];
    for(int i=r;i;i-=i&-i) Y[c2++]=seg.root[i];
    return seg.query(1,nx,k);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",a+i),tmp[nx++]=a[i];
    for(int i=0;i<m;i++)
    {
        char s[5];
        scanf("%s%d%d",s,&op[i].l,&op[i].r);
        if(s[0]=='Q')
        {
            op[i].type=0;
            scanf("%d",&op[i].k);
        }
        else
        {
            op[i].type=1;
            tmp[nx++]=op[i].r;
        }
    }
    sort(tmp,tmp+nx);
    nx=unique(tmp,tmp+nx)-tmp;
    for(int i=0;i<n;i++)
    {
        int z=lower_bound(tmp,tmp+nx,a[i])-tmp+1;
        org[z]=a[i],a[i]=z;
        add(i+1,z,1);
    }
    for(int i=0;i<m;i++)
        if(op[i].type)
        {
            int z=lower_bound(tmp,tmp+nx,op[i].r)-tmp+1;
            org[z]=op[i].r,op[i].r=z;
            add(op[i].l,a[op[i].l-1],-1);
            a[op[i].l-1]=z;
            add(op[i].l,z,1);
        }
        else
            printf("%d\n",org[query(op[i].l,op[i].r,op[i].k)]);
    return 0;
}
