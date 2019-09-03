#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[100005],s=0,ss=0;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i),s+=a[i],ss+=a[i]*a[i];
    for(int i=1;i<=n;i++)
        printf("%lld ",ss-2*a[i]*s+n*a[i]*a[i]);
    return 0;
}
