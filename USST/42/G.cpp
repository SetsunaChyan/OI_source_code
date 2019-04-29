#include <bits/stdc++.h>
using namespace std;

int n,t,dp[1000005];

void zeroone(int x,int v)
{
    for(int k=t;k>=x;k--)
        if(~dp[k-x]) dp[k]=max(dp[k],dp[k-x]+v);
}

void cp(int x,int w)
{
    int now=1,last=w;
    while(now<=last)
    {
        zeroone(x*now,now);
        last-=now;
        now<<=1;
    }
    if(last) zeroone(x*last,last);
}

int main()
{
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++)
    {
        int x,w;
        scanf("%d%d",&x,&w);
        cp(x,w);
    }
    if(~dp[t])
        printf("%d",dp[t]);
    else
        printf("0");
    return 0;
}