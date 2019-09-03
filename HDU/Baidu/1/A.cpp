#include <bits/stdc++.h>
using namespace std;

int a[1000005],b[1000005],n,la,lb;

void solve()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=0;i<n;i++) scanf("%d",b+i);
    for(int i=n-1;i>=0;i--)
        if(a[i])
        {
            la=i;
            break;
        }
    for(int i=n-1;i>=0;i--)
        if(b[i])
        {
            lb=i;
            break;
        }
    if(la>lb)
    {
        printf("1/0\n");
        return;
    }
    if(la<lb)
    {
        printf("0/1\n");
        return;
    }
    int k=__gcd(a[la],b[la]);
    printf("%d/%d\n",a[la]/k,b[la]/k);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
