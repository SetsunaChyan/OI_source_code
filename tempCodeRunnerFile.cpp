#include <cstdio>
#include <memory.h>
#include <cstring>

typedef long long ll;
ll n,m,t,act,e[60][70][70],z[70][70],op[9][9];
char s[10][10];

inline ll max(ll a,ll b){return a>b?a:b;}

void multi(ll x[70][70],ll y[70][70],ll n)
{
    ll tmp[70][70];
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                tmp[i][j]+=x[i][k]*y[k][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            x[i][j]=tmp[i][j];
}

void fp(ll x[70][70],ll y,ll n)
{
    ll ret[70][70];
    memset(ret,0,sizeof(ret));
    for(int i=0;i<n;i++)
        ret[i][i]=1;
    while(y)
    {
        if(y&1) multi(ret,x,n);
        multi(x,x,n);
        y>>=1;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            x[i][j]=ret[i][j];
}

int main()
{
    memset(e,0,sizeof(e));
    scanf("%lld%lld%lld%lld",&n,&m,&t,&act);
    ll ln=n*m+1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%1d",&op[i][j]);
    for(int i=0;i<act;i++)
        scanf("%s",s[i]);
    for(int tm=0;tm<60;tm++)
    {
        e[tm][ln-1][ln-1]=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                int now=i*m+j;
                char c=s[op[i][j]][tm%strlen(s[op[i][j]])];
                if(c>='0'&&c<='9')
                {
                    e[tm][now][now]=1;
                    e[tm][now][ln-1]=c-'0';
                }
                if(c=='N'&&i)
                    e[tm][(i-1)*m+j][now]=1;
                if(c=='W'&&j)
                    e[tm][i*m+(j-1)][now]=1;
                if(c=='S'&&i!=n-1)
                    e[tm][(i+1)*m+j][now]=1;
                if(c=='E'&&j!=m-1)
                    e[tm][i*m+(j+1)][now]=1;
            }
    }
    for(int i=0;i<ln;i++)
        for(int j=0;j<ln;j++)
            z[i][j]=e[59][i][j];
    for(int i=58;i>=0;i--)
        multi(z,e[i],ln);
    fp(z,t/60,ln);
    t%=60;
    for(int i=t-1;i>=0;i--)
        multi(z,e[i],ln);
    ll ans=0;
    for(int i=0;i<ln-1;i++)
        ans=max(ans,z[i][ln-1]);
    printf("%lld",ans);
    return 0;
}