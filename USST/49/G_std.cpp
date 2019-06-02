#include <bits/stdc++.h>
using namespace std;

int is_prime(int x)
{
    if(x<=1) return 0;
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return 0;
    return 1;
}

int main()
{
    int l,r,sum=0;
    scanf("%d%d",&l,&r);
    for(int i=l;i<=r;i++)
        sum+=is_prime(i)*i;
    printf("%d",sum);
    return 0;
}