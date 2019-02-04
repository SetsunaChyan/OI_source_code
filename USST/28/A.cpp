#include <cstdio>
#include <memory.h>

int vis[10005],n;

void d(int x)
{
    int r=x;
    while(x)
    {
        r+=x%10;
        x/=10;
    }
    if(r<=10000)
    {     
        vis[r]=1;
        d(r);
    }
}

int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        if(!vis[i])
        {
            d(i);
            printf("%d\n",i);
        }
    return 0;
}