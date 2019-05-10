#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,a[10005],b[10005],c[10005],tmp[10005];

int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<m;i++) scanf("%lld",&b[i]);
    for(int i=0;i<m;i++) scanf("%lld",&c[i]);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            tmp[j]=b[i]^a[j];
        sort(tmp,tmp+n);
        printf("%lld",tmp[c[i]-1]);
    }
    return 0;
}