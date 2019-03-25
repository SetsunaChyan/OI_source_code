#include <cstdio>

int n,ret;

void dfs(int last,int now)
{
    if(now==1)
    {
        ret++;
        return;
    }
    for(int i=last;i<=now;i++)
        if(now%i==0) dfs(i,now/i);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        ret=0;
        scanf("%d",&n);
        dfs(2,n);
        printf("%d\n",ret);
    }
    return 0;
}