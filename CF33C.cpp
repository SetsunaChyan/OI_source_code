#include <bits/stdc++.h>
using namespace std;

int n,sum,a[100005],suf[100005],ans,minsuf,minpre,summ;

void solve()
{
    summ=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),summ+=a[i];
    sum=0,minsuf=0,suf[n+1]=0;
    for(int i=n;i;i--)
    {
        sum+=a[i];
        minsuf=min(minsuf,sum);
        suf[i]=minsuf;
    }
    sum=0,minpre=0,ans=summ-2*minsuf;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        minpre=min(minpre,sum);
        ans=max(ans,summ-2*suf[i+1]-2*minpre);
    }
    printf("%d\n",ans);
}

int main()
{
    int _;
    solve();
    //scanf("%d",&_);
    //while(_--) solve();
    return 0;
}
