#include <cstdio>
#include <cmath>

int k,n,l=1,r=10000000,a[10005];
double tmp;

bool check(int x)
{
    int s=0;
    for(int i=0;i<n;i++)
        s+=a[i]/x;
    if(s<k) return true;
    return false;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&tmp);
        a[i]=tmp*100.0;
    }
    while(l<r)
    {
        int m=(l+r)>>1;
        //printf("%d %d %d\n",l,m,r);
        if(check(m)) r=m; else l=m+1;
    }
    if(l>1)
        printf("%.2lf",(l-1)/100.0);
    else
        printf("0.00");
    
    return 0;
}