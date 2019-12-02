#include <bits/stdc++.h>
using namespace std;

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        int a,b,f=0;
        scanf("%d%d",&a,&b);
        if(a==b) f=b&1;
        else if(a==b+1) f=1-(b&1);
        else f=1;
        if(f) printf("Kilani\n"); else printf("Ayoub\n");
    }
    return 0;
}
