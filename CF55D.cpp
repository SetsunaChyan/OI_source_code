#include <cstdio>
#include <memory.h>

typedef long long ll;
ll dp[20][2525][50],l,r;
int a[20],lcm2num[2525],tot=0;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}

ll dfs(int p,int sum,int prelcm,bool limit)
{
    if(p==-1) return sum%prelcm==0;
    ll &d=dp[p][sum][lcm2num[prelcm]],ret=0;
    if(~d&&!limit) return d;
    int n=limit?a[p]:9;
    for(int i=0;i<=n;i++)
        ret+=dfs(p-1,(sum*10+i)%2520,i?lcm(i,prelcm):prelcm,limit&&a[p]==i);
    if(!limit) d=ret;
    return ret;
}

ll solve(ll x)
{
    int k=0;
    while(x)
    {
        a[k++]=x%10;
        x/=10;
    }
    return dfs(k-1,0,1,true);
}

int main()
{
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=2520;i++)
        if(2520%i==0) lcm2num[i]=tot++;
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",solve(r)-solve(l-1));
    }
    return 0;
}