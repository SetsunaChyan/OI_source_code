#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a,b,c;

int main()
{
    while(~scanf("%d %d %d",&a,&b,&c))
    {
        int x=a*b;
        int y=c-b;
        int g=__gcd(x,y);
        x/=g;
        y/=g;
        printf("%d/%d\n",x,y);
    }
    return 0;
}
