#include <cstdio>
#include <memory.h>

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    int n,m,f[30001];
    memset(f,0,sizeof(f));
    scanf("%d%d",&m,&n);
    while(n--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        y=x*y;
        for(int i=m;i>=x;i--)
            f[i]=max(f[i],f[i-x]+y);
    }
    printf("%d",f[m]);
    return 0;
}
