#include <bits/stdc++.h>
using namespace std;

int n,cnt[4005][4005],x[3005],y[3005];
long long ans=0;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&x[i],&y[i]),cnt[x[i]+=2000][y[i]+=2000]=1;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            if((x[i]+x[j])%2) continue;
            if((y[i]+y[j])%2) continue;
            ans+=cnt[(x[i]+x[j])/2][(y[i]+y[j])/2];
        }
    printf("%lld",ans);
    return 0;
}
