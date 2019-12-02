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
        if(a<=b&&a<=c) printf("First\n");
        else if(b<=a&&b<=c) printf("Second\n");
        else printf("Third\n");
    }
    return 0;
}
