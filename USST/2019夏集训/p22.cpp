#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pos=0,neg=0;
int n,a[1000005];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i-1]) pos+=a[i]-a[i-1];
        else neg+=a[i-1]-a[i];
    }
    printf("%lld\n%lld",max(pos,neg),abs(pos-neg)+1);
    return 0;
}
