#include <cstdio>

const int mod=100003;
int n,k,g[100005];

int main()
{
    g[0]=1;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        g[i]=0;
        for(int j=1;j<=k;j++)
            if(j<=i) g[i]=(g[i]+g[i-j])%mod;
    }
    printf("%d",g[n]);
    return 0;
}