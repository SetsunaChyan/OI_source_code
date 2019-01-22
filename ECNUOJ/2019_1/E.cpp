#include <cstdio>

long long sum,a[6];
double ans;

inline double max(double a,double b){return a>b?a:b;}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        sum=0,ans=0;
        for(int i=0;i<6;i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        for(int i=0;i<6;i++)
            ans=max(ans,(double)a[i]/sum*(i+1));
        printf("%.12lf\n",ans);
    }
    return 0;
}