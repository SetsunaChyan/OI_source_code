#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[3],k;

int main()
{
    scanf("%lld%lld%lld%lld",a,a+1,a+2,&k);
    if(a[0]+a[1]+a[2]-3<=k) return printf("%lld",a[0]*a[1]*a[2]),0;
    sort(a,a+3);
    if(3*(a[0]-1)<=k)
    {
        ll x,y,z;
        x=y=z=k/3;
        if(k%3==1) x++;
        else if(k%3==2) y++,x++;
        printf("%lld",(x+1)*(y+1)*(z+1));
    }
    else if(a[0]-1+2*(a[1]-1)<=k)
    {
        ll x,y,z;
        x=a[0]-1;
        y=k/2;
        z=k-y;
        printf("%lld",(x+1)*(y+1)*(z+1));
    }
    else
    {
        ll x,y,z;
        x=a[0]-1,y=a[1]-1,z=k-x-y;
        printf("%lld",(x+1)*(y+1)*(z+1));
    }
    return 0;
}
