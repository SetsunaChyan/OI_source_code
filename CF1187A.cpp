#include <bits/stdc++.h>
using namespace std;

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        printf("%d\n",a-min(b,c)+1);
    }

    return 0;
}
