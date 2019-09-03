#include <bits/stdc++.h>
using namespace std;

int n,a,b;

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d",&a,&b,&n);
        n%=3;
        if(n==0) printf("%d\n",a);
        else if(n==1) printf("%d\n",b);
        else if(n==2) printf("%d\n",a^b);
    }
    return 0;
}
