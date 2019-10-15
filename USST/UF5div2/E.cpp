#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll a,b;
ll s;

int main()
{
    scanf("%llu%llu",&a,&b);
    s=a;
    s+=b;
    if(b>a)
    {
        printf("-1");
        return 0;
    }
    if(s&1)
    {
        printf("-1");
        return 0;
    }
    printf("%llu %llu",a-s/2,s/2);
    return 0;
}
