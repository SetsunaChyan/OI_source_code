#include <cstdio>
#include <memory.h>

int n,m[105],g[105],a[105][105],now,sum=0,last=-1;

int main()
{
    memset(g,0,sizeof(g));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m[i]);
        sum+=m[i];
    }
    sum*=10;
    now=0;
    for(int i=1;i<=sum;i++)
    {
        for(int j=last,k=0;k<n;k++)
        {
            j=(j+1)%n;
            if(g[j]>=m[j]*10) continue;
            if(j==last)
            {
                now+=2;
                a[j][g[j]]=now;
                g[j]++;
                break;
            }
            now+=1;
            a[j][g[j]]=now;
            g[j]++;
            last=j;
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("#%d\n",i+1);
        for(int k=0;k<m[i];k++)
        {
            for(int j=0;j<9;j++)
                printf("%d ",a[i][k*10+j]);
            printf("%d\n",a[i][k*10+9]);
        }
    }
    return 0;
}