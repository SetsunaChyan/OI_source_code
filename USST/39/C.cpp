#include <cstdio>
#include <memory.h>

int n,vis[300005],m[2][300005],ans=0;

inline int abs(int x){return x<0?-x:x;}
inline int max(int a,int b){return a>b?a:b;}

int main()
{
    memset(vis,0,sizeof vis);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&m[0][i]);
    for(int i=0;i<n;i++) scanf("%d",&m[1][i]);
    for(int i=0;i<n;i++)
    {
        if(vis[m[0][i]]) continue;
        vis[m[0][i]]=1;
        int d1=0,d2=0;
        for(int j=n-1;j>=0;j--)
            if(m[1][j]!=m[0][i]||m[0][i]==0&&m[1][j]==0)
            {
                d1=1+abs(i-j);
                break;
            }
        for(int j=n-1;j>=0;j--)
            if(m[0][j]!=m[0][i]||m[0][i]==0&&m[0][j]==0)
            {
                d2=abs(i-j);
                break;
            }
        d1=max(d1,d2);
        ans=max(ans,d1);
    }
    memset(vis,0,sizeof vis);
    for(int i=0;i<n;i++)
    {
        if(vis[m[1][i]]) continue;
        vis[m[1][i]]=1;
        int d1=0,d2=0;
        for(int j=n-1;j>=0;j--)
            if(m[1][j]!=m[1][i]||m[1][i]==0&&m[1][j]==0)
            {
                d1=abs(i-j);
                break;
            }
        for(int j=n-1;j>=0;j--)
            if(m[0][j]!=m[1][i]||m[1][i]==0&&m[0][j]==0)
            {
                d2=1+abs(i-j);
                break;
            }
        d1=max(d1,d2);
        ans=max(ans,d1);
    }
    printf("%d",ans);
    return 0;
}