#include <cstdio>

typedef long long ll;
ll n,m;

int main()
{
    scanf("%lld%lld",&n,&m);
    if(n>m){ll t=n;n=m;m=t;}
    if(n>=3&&m>=4) printf("%lld",n*m*(n*m-1)/2);
    else if(n<=1||n==2&&m==2) printf("0");
    else if(n==2) printf("%lld",(m+1)/2*((m+1)/2-1)+m/2*(m/2-1));
    else printf("28");                          
    return 0;
}