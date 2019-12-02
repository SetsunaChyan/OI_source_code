#include <bits/stdc++.h>
using namespace std;

int n,a[1000005],L[1000005],R[1000005],last[10000005],fa[1000005];
vector<int> p[10000005];

void seive()
{
    int n=10000000;
    for(int i=2;i<=n;i++)
        if(p[i].size()==0)
            for(int j=i;j<=n;j+=i) p[j].push_back(i);
}

bool gao(int rt,int l,int r)
{
    if(l>r) return 1;
    int ll=l,rr=r;
    while(ll<=rr)
    {
        if(L[ll]<l&&R[ll]>r)
        {
            fa[ll]=rt;
            return gao(ll,l,ll-1)&&gao(ll,ll+1,r);
        }
        if(L[rr]<l&&R[rr]>r)
        {
            fa[rr]=rt;
            return gao(rr,l,rr-1)&&gao(rr,rr+1,r);
        }
        ll++,rr--;
    }
    return false;
}

int main()
{
    seive();
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        int t=a[i],pos=0;
        for(auto pp:p[a[i]])
        {
            pos=max(last[pp],pos);
            last[pp]=i;
            while(t%pp) t/=pp;
        }
        L[i]=pos;
    }
    for(int i=1;i<=1e7;i++) last[i]=n+1;
    for(int i=n;i>=1;i--)
    {
        int t=a[i],pos=n+1;
        for(auto pp:p[a[i]])
        {
            pos=min(last[pp],pos);
            last[pp]=i;
            while(t%pp) t/=pp;
        }
        R[i]=pos;
    }
    //for(int i=1;i<=n;i++) printf("! %d %d\n",L[i],R[i]);
    if(gao(0,1,n))
        for(int i=1;i<=n;i++)
            printf("%d ",fa[i]);
    else
        printf("impossible");
    return 0;
}
