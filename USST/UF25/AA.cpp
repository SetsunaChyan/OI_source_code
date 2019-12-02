
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[3],k;

int main()
{
    scanf("%lld%lld%lld%lld",a,a+1,a+2,&k);
    if(a[0]+a[1]+a[2]-3<=k) return printf("%lld",a[0]*a[1]*a[2]),0;
    sort(a,a+3);
    ll x,y,z;
    x=y=z=k/3;
    if(k%3==2) x++,y++;
    else if(k%3==1) x++;
    if(x>=a[0]) y+=x-a[0]+1,x=a[0]-1;
    y=z=(k-x)/2;
    if((k-x)&1) y++;
    if(y>=a[1]) z+=y-a[1]+1,y=a[1]-1;
    printf("%lld",(x+1)*(y+1)*(z+1));
    return 0;
}
