#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

ll a[40],dp[40],l,r,p2[40];
ll c[40][40];

int dfs(int pos,bool limit)
{
    if(pos==-1) return 1;
    if(!limit&&dp[pos]!=-1) return dp[pos];
    int up=limit?a[pos]:1;
    int tmp=0;
    for(int i=0;i<=up;i++)
    {
        //tmp+=p2[pos];
        if(i) tmp+=dfs(pos-1,limit&&i==a[pos]);
        else
        {
            tmp+=dfs(pos-1,limit&&i==a[pos]);
            for(int j=pos;j<=pos;j++)
                tmp+=c[pos][j]*p2[pos-j];
        }
    }
    if(!limit) dp[pos]=tmp;
    return tmp;
}

int solve(int x)
{
    if(x==-1) return 0;
    memset(dp,-1,sizeof(dp));
    int pos=0;
    while(x)
    {
        a[pos++]=x%2;
        x/=2;
    }
    return dfs(pos-1,true);
}

void gao()
{
    scanf("%lld%lld",&l,&r);
    printf("%lld\n",(solve(r)-solve(l-1))*2);
}

signed main()
{
    p2[0]=1;
    for(int i=1;i<32;i++) p2[i]=p2[i-1]<<1;
    c[1][0]=c[1][1]=1;
    for(int i=2;i<32;i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++) c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    int _;
    scanf("%lld",&_);
    while(_--) gao();
    return 0;
}
