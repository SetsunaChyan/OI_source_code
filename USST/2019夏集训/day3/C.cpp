#include <bits/stdc++.h>
using namespace std;

int n,vis[2000005],tot=0,prime[200005];

void sel(int n)
{
    memset(vis,0,sizeof(vis));
    for(int i=2;i<=n;i++)
        if(!vis[i])
        {
            prime[tot++]=i;
            for(int j=i<<1;j<=n;j+=i) vis[j]=1;
        }
}

int main()
{
    sel(2000000);
    scanf("%d",&n);
    int a,b=0;
    a=prime[lower_bound(prime,prime+tot,n)-prime-1];
    b=prime[lower_bound(prime,prime+tot,n)-prime];
    if(b==n) printf("0");
    else printf("%d",b-a);
    return 0;
}
