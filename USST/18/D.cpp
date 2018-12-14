#include <cstdio>
#include <memory.h>

int f[1000*1000+50],n,m,k,e;

inline int max(int a,int b){return a>b?a:b;}
inline int abs(int x){return x<0?-x:x;}

int g(int x,int y)
{
    int t;
    if(x>y){t=x;x=y;y=t;}
    if(x==1) return y-1;
    if(x==0) return 0;
    if(x&1) return 1+g(x/2,y)+g(x/2+1,y);
    return 1+2*g(x/2,y);
}

int main()
{
    scanf("%d%d%d",&n,&m,&e);
    int k=n*m/2;
    printf("%d\n",g(n,m));
    for(int i=1;i<=k;i++)
        f[i]=-0x3f3f3f3f;
    f[0]=0;
    for(int i=0;i<e;i++)
    {
        int x;
        scanf("%d",&x);
        for(int i=k;i>=x;i--)
            f[i]=max(f[i],f[i-x]+x);
    }
    int g;
    for(g=k;g>=0;g--)
        if(f[g]>=0) break;
    printf("%d",abs(n*m-g-g));
    return 0;
}
