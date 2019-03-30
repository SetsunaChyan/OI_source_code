#include <cstdio>
#include <memory.h>

const int mod=6;
int a[1000][1000],b[1000][1000],c[1000][1000],ans[1000][1000],base[1000][1000],n,k;

void multi(int ret[1000][1000],int x[1000][1000],int y[1000][1000],int a,int b,int c)
{
    int tmp[a][c];
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<a;i++)
        for(int j=0;j<c;j++)
            for(int k=0;k<b;k++)
                tmp[i][j]=(tmp[i][j]+x[i][k]*y[k][j]%6)%6;
    for(int i=0;i<a;i++)
        for(int j=0;j<c;j++)
            ret[i][j]=tmp[i][j];
}

void fp(int ret[1000][1000],int x[1000][1000],int y,int n)
{
    for(int i=0;i<n;i++)
        ret[i][i]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            base[i][j]=x[i][j];
    while(y)
    {
        if(y&1) multi(ret,ret,base,n,n,n);
        multi(base,base,base,n,n,n);
        y>>=1;
    }
}

int main()
{
    while(~scanf("%d%d",&n,&k)&&n&&k)
    {
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n;i++)
            for(int j=0;j<k;j++)
                scanf("%d",&a[i][j]);
        for(int i=0;i<k;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&b[i][j]);
        multi(c,b,a,k,n,k);
        fp(ans,c,n*n-1,k);
        multi(ans,ans,b,k,k,n);
        multi(ans,a,ans,n,k,n);
        int sum=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                sum+=ans[i][j];
        printf("%d\n",sum);
    }
    return 0;
}