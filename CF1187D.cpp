#include <bits/stdc++.h>
using namespace std;

int n,a[300005],b[300005],cnt[300005],x,p[300005],r[300005];

inline int lowbit(int x){return x&-x;}

void add(int x,int y)
{
    for(;x<=n;x+=lowbit(x)) cnt[x]+=y;
}

int sum(int x)
{
    int ret=0;
    for(;x;x-=lowbit(x)) ret+=cnt[x];
    return ret;
}

void solve()
{
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        cnt[i]=r[i]=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
        a[i]=sum(p[i]-1);
        add(p[i],1);
        r[p[i]]++;
    }
    for(int i=0;i<=n;i++)
        cnt[i]=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        b[i]=sum(p[i]-1);
        add(x,1);
        r[x]--;
    }
    for(int i=1;i<=n;i++)
        if(r[i])
        {
            printf("NO\n");
            return;
        }
    for(int i=0;i<n;i++)
        if(a[i]>b[i])
        {
            printf("NO\n");
            return;
        }
    printf("YES\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)  solve();
    return 0;
}

