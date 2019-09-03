#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum;
int n,l,r,a[2000];

int main()
{
    scanf("%d%d%d",&n,&l,&r);
    for(int i=0;i<=n;i++) a[i]=1;
    for(int i=1;i<l;i++) a[i]=a[i-1]*2;
    for(int i=0;i<n;i++) sum+=a[i];
    printf("%lld",sum);
    sum=0;
    for(int i=0;i<=n;i++) a[i]=1;
    for(int i=1;i<r;i++) a[i]=a[i-1]*2;
    for(int i=r;i<=n;i++) a[i]=a[i-1];
    for(int i=0;i<n;i++) sum+=a[i];
    printf(" %lld",sum);
    return 0;
}
