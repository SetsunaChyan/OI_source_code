#include <cstdio>

const double EPS=1e-10;
double l,r,mid,pre[100001];
int n,s,t,a[100001],q[100001];

bool check(double x)
{
    pre[0]=0;
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i-1]-x;
    int h=0,e=0;
    for(int i=s;i<=n;i++)
    {
        while(h!=e&&pre[q[e-1]]>=pre[i-s]) e--;
        q[e++]=i-s;
        if(q[h]<i-t) h++;
        if(pre[i]-pre[q[h]]>=0)
            return true;
    }
    return false;
}

int main()
{
    scanf("%d%d%d",&n,&s,&t);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    r=n*10000.0;l=-r;
    while(r-l>EPS)
    {
        mid=(l+r)/2.0;
        if(check(mid))
            l=mid+EPS;
        else
            r=mid-EPS;
    }
    printf("%.3lf\n",(l+r)/2.0);
    return 0;
}
