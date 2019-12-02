#include <bits/stdc++.h>
using namespace std;

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(__gcd(a,b)==1) printf("Finite\n");
        else printf("Infinite\n");
    }

    return 0;
}
