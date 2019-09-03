#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
int n,fa1[MAXN],fa2[MAXN],N,ans[MAXN],a[MAXN],pos,vis[MAXN];

struct SEG
{
    int seg[MAXN<<2];

    void pushup(int rt)
    {
        seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
    }

    void build(int rt,int l,int r)
    {
        seg[rt]=0;
        if(l==r) return;
        int m=l+r>>1;
        build(rt<<1,l,m);
        build(rt<<1|1,m+1,r);
    }

    void modify(int rt,int l,int r,int x,int y)
    {
        if(l==r)
        {
            seg[rt]=y;
            return;
        }
        int m=l+r>>1;
        if(x<=m) modify(rt<<1,l,m,x,y);
        else modify(rt<<1|1,m+1,r,x,y);
        pushup(rt);
    }

    int query(int rt,int l,int r,int L,int R)
    {
        if(L<=0||R>N||R<L) return 0;
        if(L<=l&&r<=R) return seg[rt];
        int m=l+r>>1,ret=0;
        if(L<=m) ret=max(ret,query(rt<<1,l,m,L,R));
        if(m<R) ret=max(ret,query(rt<<1|1,m+1,r,L,R));
        return ret;
    }
}seg1,seg2;

int _find(int fa[],int x)
{
    if(x==fa[x]) return x;
    return fa[x]=_find(fa,fa[x]);
}

void _merge(int fa[],int x,int y) //x->y
{
    x=_find(fa,x),y=_find(fa,y);
    if(x!=y) fa[x]=y;
}

void solve()
{
    scanf("%d",&n);
    N=2*n;
    seg1.build(1,1,N);
    seg2.build(1,1,N);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=0;i<=N+1;i++)
        fa1[i]=fa2[i]=i,vis[i]=0,ans[i]=0;;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<0)
        {
            pos=seg1.query(1,1,N,-a[i]+1,N)+1;
            pos=_find(fa1,pos);
            if(pos>n+i)
            {
                printf("-1\n");
                return;
            }
            ans[pos]=-a[i];
            vis[-a[i]]=1;
            _merge(fa1,pos,pos+1);
            _merge(fa2,pos,pos-1);
            seg1.modify(1,1,N,-a[i],n+i-1);
        }
        else
        {
            pos=_find(fa2,n+i-1);
            if(pos<=seg2.query(1,1,N,1,a[i]-1))
            {
                printf("-1\n");
                return;
            }
            ans[pos]=a[i];
            vis[a[i]]=1;
            _merge(fa1,pos,pos+1);
            _merge(fa2,pos,pos-1);
            seg2.modify(1,1,N,a[i],n+i-1);
        }
    }
    for(int i=1;i<=N;i++)
        if(!vis[i])
        {
            pos=seg1.query(1,1,N,i+1,N)+1;
            pos=_find(fa1,pos);
            if(pos>N)
            {
                printf("-1\n");
                return;
            }
            ans[pos]=i;
            vis[i]=1;
            _merge(fa1,pos,pos+1);
            _merge(fa2,pos+1,pos);
            seg1.modify(1,1,N,i,n+i-1);
        }

    //check
    priority_queue<int,vector<int>,greater<int> > q1;
    priority_queue<int> q2;
    for(int i=1;i<=N;i++) vis[i]=0;
    for(int i=1;i<=n;i++)
    {
        q1.push(ans[i]);
        q2.push(ans[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]<0)
        {
            while(!q1.empty()&&vis[q1.top()]) q1.pop();
            if(q1.empty()||q1.top()!=-a[i])
            {
                printf("-1\n");
                return;
            }
            vis[q1.top()]=1;
            q1.pop();
            q1.push(ans[i+n]);
            q2.push(ans[i+n]);
        }
        else
        {
            while(!q2.empty()&&vis[q2.top()]) q2.pop();
            if(q2.empty()||q2.top()!=a[i])
            {
                printf("-1\n");
                return;
            }
            vis[q2.top()]=1;
            q2.pop();
            q1.push(ans[i+n]);
            q2.push(ans[i+n]);
        }
    }

    for(int i=1;i<=N;i++)
        printf("%d ",ans[i]);
    puts("");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
