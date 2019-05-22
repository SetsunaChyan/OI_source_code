#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
ll a,b;

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%llu%llu",&a,&b);
        b+=11*(a/1000)+(a%1000)/100;
        printf("%.3lf\n",b*0.012/23.0);
    }
    return 0;
}