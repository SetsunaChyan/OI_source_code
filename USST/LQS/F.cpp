#include <cstdio>
#include <memory.h>

int n;
double f[200][2],a[200];

inline double max(double a,double b){return a>b?a:b;}

int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data2.out","w",stdout);
    memset(f,0,sizeof(f));
    f[0][0]=100;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        double m0=0,m1=0;
        scanf("%lf",&a[i]);
        for(int j=0;j<i;j++)
        {
            m0=max(f[j][0],m0);
            m1=max(f[j][1],m1);
        }
        f[i][0]=max(m1/a[i],m0);
        f[i][1]=max(m0*a[i],m1);
    }
    printf("%.2lf",f[n][0]);
    return 0;
}