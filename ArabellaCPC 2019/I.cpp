#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[300005],ls,ln,rs,rn,s;

void gao()
{
    for(int i=0,l=0,r=n-1;i<n;i++)
    {
        if(i&1)
        {
            s+=ls-ln*a[l]+rn*a[l]-rs;
            ls+=a[l],ln++,l++;
        }
        else
        {
            s+=ls-ln*a[r]+rn*a[r]-rs;
            rs+=a[r],rn++,r--;
        }
        if(i) printf("%lld ",-s);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",a+i);
    sort(a,a+n);
    gao();
    return 0;
}
