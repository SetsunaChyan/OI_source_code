#include <bits/stdc++.h>
using namespace std;

double l,r,m1,m2;
int pos,neg,zero,n,x[100005],y[100005];

double f(double mid)
{
    double ret=0,xx,tmp;
    for(int i=0;i<n;i++)
    {
        xx=fabs(x[i]-mid);
        tmp=fabs(xx*xx+(double)y[i]*y[i])/2/y[i];
        ret=max(ret,tmp);
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",x+i,y+i);
        if(y[i]==0) zero++;
        else if(y[i]<0) neg++,y[i]=-y[i];
        else pos++;
    }
    if(zero>1||pos>0&&neg>0)
    {
        printf("-1");
        return 0;
    }
    l=-1e7,r=1e7;
    for(int i=0;i<100;i++)
    {
        double tmpl=l+(r-l)/3,tmpr=r-(r-l)/3;
		if(f(tmpl)>f(tmpr)) l=tmpl;
		else r=tmpr;
    }
    printf("%.10f",f(l));
    return 0;
}
