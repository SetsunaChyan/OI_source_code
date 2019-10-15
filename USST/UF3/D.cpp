#include <bits/stdc++.h>
using namespace std;

int n,x;
double mx=1e14,mm=0;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        mm=max(mm,(double)x*10.0/i);
        mx=min(mx,(double)(x+1)*10.0/i);
    }
    //printf("QAQ %f %f\n",mm,mx);
    mm+=1e-9;
    mx-=1e-9;
    mm=mm*(n+1)-x*10;
    mx=mx*(n+1)-x*10;
    int a=mm/10,b=mx/10;
    //printf("QAQ %f %f\n",mm,mx);
    //printf("QAQ %d %d\n",a,b);
    if(a==b) printf("unique\n%d",x+a);
    else printf("not unique");
    return 0;
}
