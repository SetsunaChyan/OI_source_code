#include <cstdio>
#include <memory.h>

long long g[501][4];

int main()
{
    int _;
    long long x,a,b,c;
    memset(g,0,sizeof(g));
    for(int i=1;i<=500;i++)
    {
        g[i][1]=i;
        if(i>=2) g[i][2]=i*(i-1)/2;
        if(i>=3) g[i][3]=i*(i-1)*(i-2)/2/3;
    }
    scanf("%d",&_);
    while(_--)
    {
        int flag=0;
        scanf("%lld",&x);
        for(int i=2;i<=500;i++)
            if(!flag)
            for(int j=1;j<i;j++)
                if(!flag)
                for(int k=0;k<j;k++)
                {
                    if(g[i][3]+g[j][2]+g[k][1]==x)
                    {
                        flag=1;
                        printf("%d%d%d\n",i,j,k);
                        break;
                    }
                }

    }
    return 0;
}