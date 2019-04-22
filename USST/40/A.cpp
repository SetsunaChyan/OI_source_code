#include <bits/stdc++.h>
using namespace std;

int x;
long long t;

int cal(int x)
{
    int ret=0;
    while(x)
    {
        ret+=x%10;
        x/=10;
    }
    return ret;
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&x);
        t=0;
        while(t*10+9<=x) t=t*10+9;
        printf("%d\n",cal(t)+cal(x-t));
    }
    return 0;
}