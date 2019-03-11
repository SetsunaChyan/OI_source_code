#include <cstdio>
#include <memory.h>

int m,n,dp[32000];
struct node
{
    int w[4],v[4],tot;
}e[70];

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    memset(dp,0,sizeof(dp));
    memset(e,0,sizeof(e));
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(z==0)
        {
            for(int j=0;j<4;j++)
            {
                e[i].w[j]=x;
                e[i].v[j]=x*y;    
            }
        }
        else
        {
            z--;
            e[z].tot++;
            e[z].w[e[z].tot]+=x;
            e[z].w[3]+=x;
            e[z].v[e[z].tot]+=x*y;
            e[z].v[3]+=x*y;
        }
    }
    for(int i=0;i<n;i++)
        for(int j=m;j>=0;j--)
            for(int k=0;k<4;k++)
                if(j>=e[i].w[k]) dp[j]=max(dp[j-e[i].w[k]]+e[i].v[k],dp[j]);
    printf("%d",dp[m]);
    return 0;
}