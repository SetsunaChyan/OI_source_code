#include <bits/stdc++.h>
using namespace std;

const int mod=10007;
int a,b,n,k,c[1005][1005];

int fp(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y&1) ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}

int main()
{
    c[0][0]=1;
    for(int i=1;i<=1000;i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
    while(~scanf("%d%d%d%d",&a,&b,&k,&n))
        printf("%d\n",fp(a%mod,n)*fp(b%mod,k-n)%mod*c[k][n]%mod);
    return 0;
}