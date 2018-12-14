#include <cstdio>
#include <cmath>

int n=0,l,r;

bool is_prime(int x)
{
    if(x<=1) return false;
    int k=sqrt(x);
    for(int i=2;i<=k;i++)
        if(x%i==0) return false;
    return true;
}

void dfs(int dep,int sum)
{
    if(dep==6)
    {
        if(sum>=l&&sum<=r||is_prime(sum))
            n++;
        return;
    }
    for(int i=0;i<3;i++)
        dfs(dep+1,sum+i);
}

int main()
{
    scanf("%d%d",&l,&r);
    dfs(0,0);
    printf("%d",n);
    return 0;
}