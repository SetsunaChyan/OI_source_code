#include <bits/stdc++.h>
#define RI register int
using namespace std;

const int B=1e6+5;
const int MAXN=1e5+5;
int root[MAXN],wt[20],tot;
struct node
{
    int rt,lc,rc,cnt;
}seg[MAXN*300];

inline int _max(int a,int b){return a>b?a:b;}
inline int _min(int a,int b){return a<b?a:b;}

inline int read()
{
   RI s=0;
   char ch=getchar();
   while(ch<'0'||ch>'9') ch=getchar();
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s;
}

inline void write(int x)
{
    RI tot=0;
    if(x==0)
    {
        puts("0");
        return;
    }
    while(x) wt[tot++]=x%10,x/=10;
    for(RI i=tot-1;i>=0;i--)
        putchar(wt[i]+'0');
    puts("");
}

int build(int l,int r)
{
    RI p=tot++;
    seg[p].cnt=0;
    if(l==r) return p;
    RI m=l+r>>1;
    seg[p].lc=build(l,m);
    seg[p].rc=build(m+1,r);
    return p;
}

int modify(int rt,int l,int r,int x)
{
    RI p=tot++;
    seg[p]=seg[rt];
    seg[p].cnt++;
    if(l==r) return p;
    RI m=l+r>>1;
    if(x<=m) seg[p].lc=modify(seg[rt].lc,l,m,x);
    else seg[p].rc=modify(seg[rt].rc,m+1,r,x);
    return p;
}

int query(int a,int b,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return seg[b].cnt-seg[a].cnt;
    RI m=l+r>>1,ret=0;
    if(L<=m) ret+=query(seg[a].lc,seg[b].lc,l,m,L,R);
    if(m<R) ret+=query(seg[a].rc,seg[b].rc,m+1,r,L,R);
    return ret;
}

void solve()
{
    RI m,tmp,L,R,l,r,n,q,p,k,lastans;
    tot=lastans=0;
    n=read();q=read();
    root[0]=build(1,B);
    for(RI i=1;i<=n;i++)
    {
        tmp=read();
        root[i]=modify(root[i-1],1,B,tmp);
    }
    while(q--)
    {
        L=read();R=read();p=read();k=read();
        L^=lastans,R^=lastans,p^=lastans,k^=lastans;
        l=0;r=_max(p-1,B-p);
        while(l<r)
        {
            m=l+r>>1;
            query(root[L-1],root[R],1,B,_max(p-m,1),_min(p+m,B))>=k?r=m:l=m+1;
        }
        write(lastans=l);
    }
}

int main()
{
    //freopen("1008t.in","r",stdin);
    //freopen("1008t.out","w",stdout);
    RI T;
    T=read();
    while(T--) solve();
    return 0;
}
