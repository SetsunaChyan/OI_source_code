#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    a%=b;
    if(a==0)
    {
        printf("Yes");
        return 0;
    }
    int t=__gcd(a,b);
    a/=t,b/=t;
    for(int i=0;i<31;i++)
        if(b==(1<<i))
        {
            printf("Yes");
            return 0;
        }
    printf("No");
    return 0;
}
