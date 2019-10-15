#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t1,t2,t0,x1,x2,y1,y2;
double mx=1e10;

double cal(ll y1,ll y2)
{
    return double(t1*y1+t2*y2)/(y1+y2);
}

int main()
{
    scanf("%lld%lld%lld%lld%lld",&t1,&t2,&x1,&x2,&t0);
    /*l=0,r=1;sum=x1+x2;
    for(int i=0;i<100;i++)
    {
        double m=(l+r)/2;
        if(cal(m)>=t) l=m; else r=m;
    }*/
    if(t1==t2)
    {
        printf("%lld %lld",x1,x2);
        return 0;
    }
    if(t2==t0)
    {
        printf("0 %lld",x2);
        return 0;
    }
    if(t1==t0)
    {
        printf("%lld 0",x1);
        return 0;
    }
    for(int i=0;i<=x1;i++)
    {
        ll qaq=(double)i*(t0-t1)/(t2-t0);
        //printf("%d %lld\n",i,qaq);
        if(qaq>=0&&qaq<=x2&&cal(i,qaq)-t0<=mx&&cal(i,qaq)>=t0)
            mx=cal(i,qaq)-t0,y1=i,y2=qaq;
        qaq++;
        if(qaq>=0&&qaq<=x2&&cal(i,qaq)-t0<=mx&&cal(i,qaq)>=t0)
            mx=cal(i,qaq)-t0,y1=i,y2=qaq;
        qaq-=2;
        if(qaq>=0&&qaq<=x2&&cal(i,qaq)-t0<=mx&&cal(i,qaq)>=t0)
            mx=cal(i,qaq)-t0,y1=i,y2=qaq;
    }
    for(int i=0;i<=x2;i++)
    {
        ll qaq=(double)i*(t0-t2)/(t1-t0);
        //printf("%d %lld\n",i,qaq);
        if(qaq>=0&&qaq<=x1&&cal(qaq,i)-t0<=mx&&cal(qaq,i)>=t0&&i+qaq>=y1+y2)
            mx=cal(qaq,i)-t0,y2=i,y1=qaq;
        qaq++;
        if(qaq>=0&&qaq<=x1&&cal(qaq,i)-t0<=mx&&cal(qaq,i)>=t0&&i+qaq>=y1+y2)
            mx=cal(qaq,i)-t0,y2=i,y1=qaq;
        qaq-=2;
        if(qaq>=0&&qaq<=x1&&cal(qaq,i)-t0<=mx&&cal(qaq,i)>=t0&&i+qaq>=y1+y2)
            mx=cal(qaq,i)-t0,y2=i,y1=qaq;
    }
    //printf("%.10f\n %.10f\n",cal(99,33),mx);
    printf("%lld %lld",y1,y2);
    return 0;
}
