#include <bits/stdc++.h>
using namespace std;

const int MAXN=140005;
int n,m,tot,root[MAXN],x,y,a[MAXN];
char op[5];
set<int> last[1000005];

struct SEG
{
    int lc,rc,cnt;
}seg[MAXN*600];

void seg_modify(int &rt,int l,int r,int x,int y)
{
    if(rt==0)
    {
        rt=++tot;
        seg[rt].cnt=0;
        seg[rt].lc=seg[rt].rc=0;
    }
    if(l==r)
    {
        seg[rt].cnt+=y;
        return;
    }
    int m=l+r>>1;
    if(x<=m) seg_modify(seg[rt].lc,l,m,x,y);
    else seg_modify(seg[rt].rc,m+1,r,x,y);
    seg[rt].cnt=seg[seg[rt].lc].cnt+seg[seg[rt].rc].cnt;
}

int seg_query(int rt,int l,int r,int L,int R)
{
    if(rt==0) return 0;
    if(L<=l&&r<=R) return seg[rt].cnt;
    int m=l+r>>1,ret=0;
    if(L<=m) ret+=seg_query(seg[rt].lc,l,m,L,R);
    if(m<R) ret+=seg_query(seg[rt].rc,m+1,r,L,R);
    return ret;
}

void modify(int l,int r,int pos,int y)
{
    for(l;l<=n;l+=l&-l) seg_modify(root[l],1,n,pos,y);
    for(r++;r<=n;r+=r&-r) seg_modify(root[r],1,n,pos,-y);
}

int query(int l,int r)
{
    int ret=0;
    for(int i=r;i;i-=i&-i) ret+=seg_query(root[i],1,n,l,r);
    return ret;
}

int debug(int x,int y)
{
    int ret=0;
    for(int i=x;i;i-=i&-i) ret+=seg_query(root[i],1,n,y,y);
    return ret;
}

void change(int pos,int y)
{
    int l,r,k=a[pos];
    auto it=last[k].upper_bound(pos);
    if(k!=0)
    {
        if(it==last[k].end()) r=n; else r=(*it)-1;
        it=last[k].lower_bound(pos);
        if(it!=last[k].begin()) modify(pos,r,*(--it),1);
        modify(pos,r,pos,-1);
        last[k].erase(pos);
    }

    last[y].insert(pos);
    a[pos]=y;
    it=last[y].upper_bound(pos);
    if(it==last[y].end()) r=n; else r=(*it)-1;
    it=last[y].lower_bound(pos);
    if(it!=last[y].begin()) modify(pos,r,*(--it),-1);
    modify(pos,r,pos,1);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        change(i,a[i]);
        printf("SEG:\n");
        for(int k=1;k<=i;k++)
        {
            for(int j=1;j<=n;j++)
                printf("%d ",debug(k,j));
            printf("\n");
        }
    }
    while(m--)
    {
        scanf("%s%d%d",op,&x,&y);
        if(op[0]=='Q') printf("%d\n",query(x,y));
        else change(x,y);
    }
    return 0;
}
