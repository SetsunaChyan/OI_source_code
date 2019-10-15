#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum;
const int MAXN=200005;
int n,m,a[MAXN],X[20],Y[20],c1,c2,op,l,r,x,y;

namespace seg
{
    int tot,root[MAXN],cnt[MAXN*160],lc[MAXN*160],rc[MAXN*160];
    void modify(int &rt,int l,int r,int x,int y)
    {
        if(!rt) rt=++tot;
        cnt[rt]+=y;
        if(l==r) return;
        int m=l+r>>1;
        if(x<=m) modify(lc[rt],l,m,x,y);
        else modify(rc[rt],m+1,r,x,y);
    }
    int query(int l,int r,int L,int R)
    {
        int ret=0;
        if(L<=l&&r<=R)
        {
            for(int i=0;i<c1;i++) ret-=cnt[X[i]];
            for(int i=0;i<c2;i++) ret+=cnt[Y[i]];
            return ret;
        }
        int m=l+r>>1,tmpX[20],tmpY[20];
        if(L<=m)
        {
            for(int i=0;i<c1;i++) tmpX[i]=X[i],X[i]=lc[X[i]];
            for(int i=0;i<c2;i++) tmpY[i]=Y[i],Y[i]=lc[Y[i]];
            ret+=query(l,m,L,R);
            for(int i=0;i<c1;i++) X[i]=tmpX[i];
            for(int i=0;i<c2;i++) Y[i]=tmpY[i];
        }
        if(m<R)
        {
            for(int i=0;i<c1;i++) tmpX[i]=X[i],X[i]=rc[X[i]];
            for(int i=0;i<c2;i++) tmpY[i]=Y[i],Y[i]=rc[Y[i]];
            ret+=query(m+1,r,L,R);
            for(int i=0;i<c1;i++) X[i]=tmpX[i];
            for(int i=0;i<c2;i++) Y[i]=tmpY[i];
        }
        return ret;
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
        c1=c2=0;
        for(int i=l-1;i;i-=i&-i)
            X[c1++]=seg::root[i];
        for(int i=r;i;i-=i&-i)
            Y[c2++]=seg::root[i];
        return seg::query(1,n,L,R);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        if(a[i]!=a[i-1]) bit::add(i,a[i],1);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d",&x,&y);
            if(a[x]==y) continue;
            if(a[x]!=a[x-1]) bit::add(x,a[x],-1);
            if(y!=a[x-1]) bit::add(x,y,1);
            if(x!=n)
            {
                if(a[x+1]!=a[x]&&a[x+1]==y) bit::add(x+1,a[x+1],-1);
                if(a[x+1]==a[x]&&a[x+1]!=y) bit::add(x+1,a[x+1],1);
            }
            a[x]=y;
        }
        else
        {
            scanf("%d%d%d%d",&l,&r,&x,&y);
            int ans=bit::sum(l,r,x,y);
            if(a[l]==a[l-1]&&a[l]>=x&&a[l]<=y) ans++;
            printf("%d\n",ans);
        }
    }
    return 0;
}
