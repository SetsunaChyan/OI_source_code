#include <cstdio>
#include <memory.h>

int k[5005][5005],l,w,a,n,ans=0;

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    memset(k,0,sizeof k);
    scanf("%d%d%d%d",&l,&w,&a,&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==l||y==w||x==0||y==0) continue;
        k[x+1][y+1]++;
    }
    //a--;
    for(int x=1;x<=l+1;x++)
        for(int y=1;y<=w+1;y++)
            k[x][y]=-k[x-1][y-1]+k[x][y]+k[x-1][y]+k[x][y-1];
    for(int x=a;x<=l+1;x++)
        for(int y=a;y<=w+1;y++)
            ans=max(ans,k[x][y]+k[x-a][y-a]-k[x][y-a]-k[x-a][y]);
    printf("%d",ans);
    return 0;
}