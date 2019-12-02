#include <bits/stdc++.h>
using namespace std;

long long m;
const double r2=sqrt((double)2.0);
double r,ans;

int main()
{
    scanf("%lld%lf",&m,&r);
    //for(int i=0;i<m*m;i++) printf("! %d %d\n",i/m+1,m+1+i%m);
    ans=2*r*m+2*(m-1)*(2+r2)*r;
    for(int i=2;i<m;i++)
        ans+=2*(m-i)*(2*(i-1)+2*r2)*r;
    printf("%.10f",ans/m/m);
    return 0;
}
