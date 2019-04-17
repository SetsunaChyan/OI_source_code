#include <cstdio>
#include <cmath>

bool is_sqr(int x)
{
    int t=sqrt(x);
    return t*t==x;
}

int solve(int x)
{
    while(x%4==0) x/=4;
    if(is_sqr(x)) return 1;
    if(x%8==7) return 4;
    for(int i=1;i*i<=x;i++)
        if(is_sqr(x-i*i)) return 2;
    return 3;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",solve(n));
    return 0;
}