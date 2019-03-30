#include <cstdio>
#include <memory.h>

typedef long long ll;
ll e[3][3],n,m,ans[200][200];

void multi(ll x[3][3],ll y[3][3])
{
    ll tmp[3][3];
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                tmp[i][j]=(tmp[i][j]+x[i][k]*y[k][j])%m;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            x[i][j]=tmp[i][j];
}

void fp(ll x[3][3],ll y)
{
    ll ret[3][3];
    memset(ret,0,sizeof(ret));
    for(int i=0;i<3;i++)
        ret[i][i]=1;
    while(y)
    {
        if(y&1) multi(ret,x);
        multi(x,x);
        y>>=1;
    }
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            x[i][j]=ret[i][j];
}

int main()
{
    int _;
    scanf("%d",&_);
    for(int cas=1;cas<=_;cas++)
    {
        scanf("%lld%lld",&n,&m);
        memset(e,0,sizeof(e));
        e[0][0]=e[0][1]=e[1][1]=e[1][2]=e[2][1]=1;
        fp(e,n);
        n=e[0][1]%m;
        //printf("n:%lld\n",n);
        printf("Case %d: ",cas);
        if(n&1||n==0) {printf("No\n");continue;} else {printf("Yes\n");}
        for(int i=0;i<n;i++)
        {
            if(i&1)
            {
                for(int j=0;j<n-i;j++)
                    ans[i][j]=-1;
                for(int j=i;j<n;j++)
                    ans[j][n-1-i]=-1;
                continue;
            }
            for(int j=0;j<n-i;j++)
                ans[i][j]=1;
            ans[i+1][n-i-1]=0;
            for(int j=i+2;j<n;j++)
                ans[j][n-1-i]=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                printf("%d ",ans[i][j]);
            printf("\n");
        }
    }

    return 0;
}