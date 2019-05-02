#include <cstdio>
#include <cstring>

const int MAXN=50005;
int a[MAXN],maxn[MAXN<<2],minn[MAXN<<2],n,q;

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

inline void pushup(int rt)
{
    maxn[rt]=max(maxn[rt<<1],maxn[rt<<1|1]);
    minn[rt]=min(minn[rt<<1],minn[rt<<1|1]);
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        maxn[rt]=minn[rt]=a[l];
        return;
    }
    int m=(l+r)>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
    pushup(rt);
}

void query(int rt,int l,int r,int L,int R,int &maxx,int &minx)
{
    if(L<=l&&r<=R)
    {
        maxx=max(maxx,maxn[rt]);
        minx=min(minx,minn[rt]);
        return;
    }
    int m=(l+r)>>1;
    if(L<=m) query(rt<<1,l,m,L,R,maxx,minx);
    if(R>m) query(rt<<1|1,m+1,r,L,R,maxx,minx);
}

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    while(q--)
    {
        int x,y,maxx=-1,minx=0x3f3f3f3f;
        scanf("%d%d",&x,&y);
        query(1,1,n,x,y,maxx,minx);
        printf("%d\n",maxx-minx);
    }
    return 0;
}