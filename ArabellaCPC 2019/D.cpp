#include <bits/stdc++.h>
using namespace std;

int n,m,gcd1,gcd2,a[1000005];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0,x;i<m;i++)
        scanf("%d",&x),gcd2=__gcd(gcd2,x);
    sort(a,a+n);
    for(int i=1;i<n;i++) gcd1=__gcd(gcd1,a[i]-a[i-1]);
    if(gcd1%gcd2==0) printf("Yes"); else printf("No");
    return 0;
}
