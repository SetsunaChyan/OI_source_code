#include <cstdio>
#include <memory.h>

int n,a[100005],f[100005][2];

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    scanf("%d",&n);
    memset(f,0,sizeof(f));
    int x;
    scanf("%d",&x);
    f[1][1]=x;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&x);
        f[i][0]=max(f[i-1][1],f[i-1][0]);
        f[i][1]=f[i-1][0]+x;
    }
    printf("%d",max(f[n][1],f[n][0]));
    return 0;
}