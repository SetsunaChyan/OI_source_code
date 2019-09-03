#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;
const int inf=0x3f3f3f3f;
int wa[MAXN],wb[MAXN],wv[MAXN],Ws[MAXN];
int sa[MAXN],Rank[MAXN],height[MAXN];
int n,q;
char str[MAXN];

bool cmp(int *r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}

void da(const char r[],int sa[],int n,int m)
{
      int i,j,p,*x=wa,*y=wb,*t;
      for(i=0; i<m; i++) Ws[i]=0;
      for(i=0; i<n; i++) Ws[x[i]=r[i]]++;
      for(i=1; i<m; i++) Ws[i]+=Ws[i-1];
      for(i=n-1; i>=0; i--) sa[--Ws[x[i]]]=i;
      for(j=1,p=1; p<n; j*=2,m=p)
      {
            for(p=0,i=n-j; i<n; i++) y[p++]=i;
            for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
            for(i=0; i<n; i++) wv[i]=x[y[i]];
            for(i=0; i<m; i++) Ws[i]=0;
            for(i=0; i<n; i++) Ws[wv[i]]++;
            for(i=1; i<m; i++) Ws[i]+=Ws[i-1];
            for(i=n-1; i>=0; i--) sa[--Ws[wv[i]]]=y[i];
            for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
                  x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
      }
}

void calheight(const char *r,int *sa,int n)
{
      int i,j,k=0;
      for(i=1; i<=n; i++) Rank[sa[i]]=i;
      for(i=0; i<n; height[Rank[i++]]=k)
            for(k?k--:0,j=sa[Rank[i]-1]; r[i+k]==r[j+k]; k++);
      for(int i=n;i>=1;--i) ++sa[i],Rank[i]=Rank[i-1];
}

namespace zhuxishu
{
    int root[MAXN],tot=0;
    struct tree
    {
        int cnt,lc,rc;
    }seg[30*MAXN];

    void tclear()
    {
        tot=0;
    }

    int build(int l,int r)
    {
        int p=tot++;
        if(l==r)
        {
            seg[p].cnt=0;
            return p;
        }
        int m=l+r>>1;
        seg[p].lc=build(l,m);
        seg[p].rc=build(m+1,r);
        seg[p].cnt=seg[seg[p].lc].cnt+seg[seg[p].rc].cnt;
        return p;
    }

    int modify(int rt,int l,int r,int x)
    {
        int p=tot++;
        seg[p]=seg[rt];
        if(l==r)
        {
            seg[p].cnt++;
            return p;
        }
        int m=l+r>>1;
        if(x<=m) seg[p].lc=modify(seg[rt].lc,l,m,x);
        else seg[p].rc=modify(seg[rt].rc,m+1,r,x);
        seg[p].cnt=seg[seg[p].lc].cnt+seg[seg[p].rc].cnt;
        return p;
    }

    int query(int p,int q,int l,int r,int k)
    {
        if(l==r) return l;
        int m=l+r>>1;
        int lcnt=seg[seg[q].lc].cnt-seg[seg[p].lc].cnt;
        if(lcnt>=k) return query(seg[p].lc,seg[q].lc,l,m,k);
        else return query(seg[p].rc,seg[q].rc,m+1,r,k-lcnt);
    }
}

namespace SEG
{
    int seg[MAXN<<2];

    void build(int rt,int l,int r)
    {
        if(l==r)
        {
            seg[rt]=height[l];
            return;
        }
        int m=l+r>>1;
        build(rt<<1,l,m);
        build(rt<<1|1,m+1,r);
        seg[rt]=min(seg[rt<<1],seg[rt<<1|1]);
    }

    int query(int rt,int l,int r,int L,int R)
    {
        if(L<=l&&r<=R) return seg[rt];
        int m=l+r>>1,ret=inf;
        if(L<=m) ret=min(ret,query(rt<<1,l,m,L,R));
        if(m<R) ret=min(ret,query(rt<<1|1,m+1,r,L,R));
        return ret;
    }
}

void solve()
{
    scanf("%d%d",&n,&q);
    scanf("%s",str);
    zhuxishu::tclear();
    int len=strlen(str),st,lcp,sum=0;
    str[n]=0;
    da(str,sa,n+1,130);
    calheight(str,sa,len);
    height[1]=0;
    SEG::build(1,1,n);
    zhuxishu::root[0]=zhuxishu::build(1,n);
    for(int i=1;i<=n;i++)
        zhuxishu::root[i]=zhuxishu::modify(zhuxishu::root[i-1],1,n,sa[i]);
    while(q--)
    {
        int l,r,L,R,k,lq,rq;
        scanf("%d%d%d",&L,&R,&k);
        l=2;r=Rank[L];
        while(l<r)
        {
            int mid=l+r>>1;
            if(SEG::query(1,1,n,mid,r)<R-L+1) l=mid+1; else r=mid;
        }
        lq=r-1;
        if(height[Rank[L]]<R-L+1) lq=Rank[L];
        l=Rank[L]+1;r=n;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(SEG::query(1,1,n,l,mid)<R-L+1) r=mid-1; else l=mid;
        }
        rq=l;
        if(height[Rank[L]+1]<R-L+1) rq=Rank[L];
        if(rq-lq+1<k)
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n",zhuxishu::query(zhuxishu::root[lq-1],zhuxishu::root[rq],1,n,k));
    }
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
