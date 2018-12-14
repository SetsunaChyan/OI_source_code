#include <cstdio>
#include <memory.h>

int n,f[10005];

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
//ax+by=c
int main()
{
    int x,ans=0,q;
    memset(f,0,sizeof(f));
    f[0]=1;
    scanf("%d%d",&n,&q);
    n-=1;
    for(int i=q;i<=10000;i++)
        if(f[i-q]) f[i]=1;
    for(int j=0;j<n;j++)
    {
        scanf("%d",&x);
        q=gcd(x,q);
        for(int i=x;i<=10000;i++)
            if(f[i-x]) f[i]=1;
    }
    if(q!=1)
    {
        printf("INF");
        return 0;
    }
    for(int i=0;i<=10000;i++)
        if(f[i]==0) ans++;
    printf("%d",ans);
    return 0;
}