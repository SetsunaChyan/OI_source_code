#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,a[1000],mx,ans,tmp,v[105],tot;
bool vis[31];
vector<int> m;

bool check(int a,int b,int c,int d)
{
    m.clear();
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    for(int i=0;i<a;i++) m.push_back(1);
    for(int i=0;i<b;i++) m.push_back(2);
    for(int i=0;i<c;i++) m.push_back(5);
    for(int i=0;i<d;i++) m.push_back(10);
    for(int j=0;j<m.size();j++)
        for(int k=30;k>=m[j];k--)
            vis[k]|=vis[k-m[j]];
    for(int j=0;j<n;j++)
        if(!vis[v[j]]) return false;
    //for(int j=0;j<m.size();j++)
    //    printf("%d ",m[j]);
    //printf("\n");
    return true;
}

void solve()
{
    mx=0,tot=0;
    int flag=0;
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",a+i);
        if(a[i]%10) flag=1;
        mx=max(mx,a[i]);
    }
    if(flag)
    {
        printf("-1\n");
        return;
    }
    if(mx<100)
    {
        for(int i=0;i<n;i++)
            v[tot++]=a[i]%100/10;
        tmp=0;
    }
    else if(mx<200)
    {
        for(int i=0;i<n;i++)
            if(a[i]>=mx/100*100) v[tot++]=a[i]%100/10+10;
            else v[tot++]=a[i]%100/10;
        tmp=mx/100-1;
    }
    else
    {
        for(int i=0;i<n;i++)
            if(a[i]>=mx/100*100) v[tot++]=a[i]%100/10+20;
            else if(a[i]>=mx/100*100-100) v[tot++]=a[i]%100/10+10;
            else v[tot++]=a[i]%100/10;
        tmp=mx/100-2;
    }
    sort(v,v+tot);
    n=unique(v,v+tot)-v;
    ans=0x3f3f3f3f;
    for(int i=0;i<=10;i++)
        for(int j=0;j<=10;j++)
            for(int k=0;k<=4;k++)
                for(int l=0;l<=3;l++)
                    if(check(i,j,k,l)) ans=min(ans,i+j+k+l);
    printf("%lld\n",ans+tmp);
}

signed main()
{
    int _;
    scanf("%lld",&_);
    while(_--) solve();
    return 0;
}

/*
10
250410 68390 197950 31460 161120 154990 57610 56310 77660 92240
//2507

*/
