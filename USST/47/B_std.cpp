#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m,p,pro=0,ans=1;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main()
{
    scanf("%lld%lld%lld",&n,&m,&p);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                pro+=gcd(i,j)*(gcd(i,j)%k==0);
    for(int i=0;i<pro;i++)
        ans=ans*m%p;
    printf("%lld",ans);
    return 0;
}