#include <bits/stdc++.h>
using namespace std;

int a1,a2,k1,k2,n,mx,mm;

int main()
{
    scanf("%d%d%d%d%d",&a1,&a2,&k1,&k2,&n);
    mm=n-(k1-1)*a1-(k2-1)*a2;
    if(k1<k2)
    {
        mx+=min(a1,n/k1);
        n-=k1*mx;
        mx+=n/k2;
    }
    else
    {
        mx+=min(a2,n/k2);
        n-=k2*mx;
        mx+=n/k1;
    }
    printf("%d %d",max(0,mm),mx);
    return 0;
}
