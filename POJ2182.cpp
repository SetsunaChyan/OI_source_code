#include <cstdio>
#include <math.h>
#include <memory.h>

const int MAXN=1e5+50;
int BIT[MAXN],n,a[MAXN],h[MAXN];

inline int lowbit(int x)
{
    return x&-x;
}

void add(int x,int y)
{
    for(;x<=n;x+=lowbit(x)) BIT[x]+=y;
}

int sum(int x)
{
    int ret=0,sum=0;
    for(int p=(int)(log((float)n)/log(2.0));p>=0;p--)
        if(ret+(1<<p)<=n&&sum+BIT[ret+(1<<p)]<=x)
        {
            sum+=BIT[ret+(1<<p)];
            ret+=(1<<p);
        }
    return ret+1;
}

int main()
{
    scanf("%d",&n);
    memset(BIT,0,sizeof(BIT));
    add(1,1);
    a[1]=0;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&a[i]);
        add(i,1);
    }
    for(int i=n;i>=1;i--)
    {
        h[i]=sum(a[i]);
        add(h[i],-1);
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",h[i]);
    return 0;
}