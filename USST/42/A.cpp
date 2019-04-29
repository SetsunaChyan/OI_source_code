#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int l,r,vis[1000005],sum[1000005];

void sel(int n)
{
    memset(sum,0,sizeof(sum));
    memset(vis,0,sizeof(vis));
    for(int i=2;i<=n;i++)
        if(!vis[i])
            for(int j=i;j<=n;j+=i)
            {
                int t=j;
                vis[j]=1;
                while(t%i==0)
                {
                    sum[j]+=i;
                    t/=i;
                }
            }
}

int main()
{
    scanf("%d%d",&l,&r);
    sel(r);
    int cnt=0;
    for(int i=l;i<=r;i++)
        if(sum[i]==i) cnt++;
    printf("%d",cnt);
    return 0;
}