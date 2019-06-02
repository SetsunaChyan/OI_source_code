#include <bits/stdc++.h>
using namespace std;

int t,n,b,p;
double sum,sz;

int main()
{
    int cs=0;
    while(~scanf("%d%d%d",&t,&n,&b)&&t&&n&&b)
    {
        sum=0;
        while(t--)
        {
            scanf("%lf%d",&sz,&p);
            sum+=(100.0-p)*sz/b/100.0;
        }
        printf("Case %d: %.2lf\n\n",++cs,sum);
    }
    return 0;
}
