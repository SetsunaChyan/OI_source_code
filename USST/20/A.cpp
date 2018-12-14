#include <cstdio>
#include <memory.h>

int n,f[100000][11],k[100000][11];

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    //freopen("5.in","r",stdin);
    while(~scanf("%d",&n)&&n)
    {
        memset(f,-0x80,sizeof(f));
        memset(k,0,sizeof(k));
        f[0][5]=0;
        for(int i=0;i<n;i++)
        {
            int x,t;
            scanf("%d%d",&x,&t);
            k[t][x]++;
        }
        for(int i=1;i<100000;i++)
        {
            f[i][0]=max(f[i-1][0],f[i-1][1])+k[i][0];
            f[i][10]=max(f[i-1][10],f[i-1][9])+k[i][10];
            for(int j=1;j<10;j++)
                f[i][j]=max(f[i-1][j-1],max(f[i-1][j],f[i-1][j+1]))+k[i][j];
        }
        int ans=0;
        for(int i=0;i<=10;i++)
            ans=max(ans,f[100000-1][i]);
        printf("%d\n",ans);
    }
    return 0;
}