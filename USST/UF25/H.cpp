#include <bits/stdc++.h>
using namespace std;

int n,k,a[100005];

int main()
{
    scanf("%d%d",&n,&k);
    if(k==n) return printf("-1"),0;
    for(int i=2;i<=k+1;i++) a[i]=i;
    a[(k+1)%n+1]=1;
    for(int i=1;i<=n;i++)
        if(!a[i]) a[i]=(i-2+n)%n+1;
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}

