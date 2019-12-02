#include <bits/stdc++.h>
using namespace std;

int x;

int main()
{
    scanf("%d",&x);
    if(x>=0) return printf("%d",x),0;
    x=abs(x);
    if(x%10>x/10%10)
        x=x/100*10+x/10%10;
    else
        x=x/100*10+x%10;
    printf("%d",-x);
    return 0;
}
