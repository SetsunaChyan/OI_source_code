#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[50005],mm=2e9,mx;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<2*n;i++) scanf("%d",a+i);
    sort(a,a+2*n);
    for(int i=0,x;i<n;i++)
    {
        x=a[i]+a[2*n-i-1];
        mm=min(mm,x),mx=max(mx,x);
    }
    printf("%d",mx-mm);
    return 0;
}
