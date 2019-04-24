#include <bits/stdc++.h>
using namespace std;

int n,a[50],sel[30],vis[30];

bool is_prime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return false;
    return true;
}

void dfs(int dep,int last)
{
    if(dep==n)
    {
        if(is_prime(1+last))
        {
            for(int i=0;i<n-1;i++) printf("%d ",sel[i]);
            printf("%d\n",sel[n-1]);
        }
        return;
    }
    for(int i=((dep+1)&1)+2;i<=n;i+=2)
    {
        if(vis[i]||!a[i+last]) continue;
        vis[i]=1;
        sel[dep]=i;
        dfs(dep+1,i);
        vis[i]=0;
    }

}

int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    if(n&1)
    {
        printf("No");
        return 0;
    }
    sel[0]=1;
    for(int i=1;i<=45;i++)
        a[i]=is_prime(i);
    dfs(1,1);
    return 0;
}