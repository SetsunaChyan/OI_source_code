#include <cstdio>
#include <memory.h>

int a[105][105],len[105],vis[105],n,m,ans=0x3f3f3f3f;

inline int min(int a,int b){return a<b?a:b;}

void test(int x)
{
    int tot,sum=0;
    memset(vis,0,sizeof(vis));
    vis[x]=1;
    do
    {
        tot=0;
        for(int i=0;i<n;i++)
        {
            int flag=0;
            for(int j=len[i]-1;j>=0;j--)
            {
                if(flag&&vis[a[i][j]]==0) {tot++;vis[a[i][j]]=1;}
                if(vis[a[i][j]]==1) flag=1;
            }
        }
    }while(tot!=0);
    for(int i=1;i<=m;i++) sum+=vis[i];
    ans=min(ans,sum);
}

int main()
{
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&len[i]);
        for(int j=0;j<len[i];j++)
            scanf("%d",&a[i][j]);
    }
    for(int i=1;i<=m;i++)
        test(i);
    printf("%d",ans);
    return 0;
}