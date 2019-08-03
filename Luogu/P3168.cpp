#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=2e5+5;
ll pre=1,last,ans,num;
int n,m,tot,cnt,root[MAXN],id[MAXN],tmp[MAXN],org[MAXN];
priority_queue<pii,vector<pii>,greater<pii> > q;
struct opt
{
    int s,e,p;
}op[MAXN];
struct node
{
    ll val,sum;
    int lc,rc;
}seg[MAXN*30];

int build(int l,int r)
{
    int p=tot++;
    seg[p].val=seg[p].sum=0;
    if(l==r) return p;
    int m=l+r>>1;
    seg[p].lc=build(l,m);
    seg[p].rc=build(m+1,r);
    return p;
}

int modify(int rt,int l,int r,int x,int y)
{
    int p=tot++;
    seg[p]=seg[rt];
    if(l==r)
    {
        seg[p].val+=y;
        seg[p].sum+=y*org[x];
        return p;
    }
    int m=l+r>>1;
    if(x<=m) seg[p].lc=modify(seg[rt].lc,l,m,x,y);
    else seg[p].rc=modify(seg[rt].rc,m+1,r,x,y);
    seg[p].val=seg[seg[p].lc].val+seg[seg[p].rc].val;
    seg[p].sum=seg[seg[p].lc].sum+seg[seg[p].rc].sum;
    return p;
}

void query(int rt,int l,int r,int k)
{
    if(l==r)
    {
        ans+=seg[rt].sum;
        num+=seg[rt].val;
        last=org[l];
        return;
    }
    int m=l+r>>1,lcnt;
    lcnt=seg[seg[rt].lc].val;
    if(lcnt>=k)
        query(seg[rt].lc,l,m,k);
    else
    {
        ans+=seg[seg[rt].lc].sum;
        num+=lcnt;
        query(seg[rt].rc,m+1,r,k-lcnt);
    }
}

int main()
{
    scanf("%d%d",&m,&n);
    root[0]=build(1,m);
    id[0]=0;
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&op[i].s,&op[i].e,&op[i].p),tmp[i]=op[i].p;
    sort(tmp,tmp+m);
    for(int i=0;i<m;i++)
    {
        int k=lower_bound(tmp,tmp+m,op[i].p)-tmp+1;
        org[k]=op[i].p;
        op[i].p=k;
        q.emplace(op[i].s,op[i].p);
        q.emplace(op[i].e+1,-op[i].p);
    }
    while(!q.empty())
    {
        cnt++;
        pii p=q.top();q.pop();
        if(p.second>0) root[cnt]=modify(root[cnt-1],1,m,p.second,1);
        else root[cnt]=modify(root[cnt-1],1,m,-p.second,-1);
        id[p.first]=cnt;
    }
    for(int i=1;i<=n;i++)
        if(!id[i]) id[i]=id[i-1];
    for(int i=1;i<=n;i++)
    {
        ll a,b,c,x,k;
        scanf("%lld%lld%lld%lld",&x,&a,&b,&c);
        k=(a*pre%c+b)%c+1;
        ans=num=0;
        query(root[id[x]],1,m,k);
        if(num>k) ans-=last*(num-k);
        printf("%lld\n",pre=ans);
    }
    return 0;
}

/*
4 100
1 10 1
1 11 2
90 100 3
91 99 4
100 0 0 100
*/
