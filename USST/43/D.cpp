#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,k,c[70][70],ans=0;

int main()
{
    memset(c,0,sizeof(c));
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=0;i<=60;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    for(int i=4;i<=n;i++)
    {
        if(i>n||k-i<2||k-i>m) continue;
        ans+=c[n][i]*c[m][k-i];
    }
    printf("%lld",ans);
    return 0;
}
