#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        if(a%2==0&&b%2==0) printf("abdullah\n");
        else printf("hasan\n");
    }
    return 0;
}
