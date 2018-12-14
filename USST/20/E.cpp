#include <cstdio>

long long x,y;

//gcd(a,b)==x a*b/gcd(a,b)==y
//a*b==x*y
long long gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}
inline long long min(long long x,long long y){return x<y?x:y;}
inline long long max(long long x,long long y){return x>y?x:y;}

int main()
{
    scanf("%lld%lld",&x,&y);
    long long k=x*y;
    int ans=0;
    for(int i=min(x,y);i<=max(x,y);i++)
    {
        if(k%i) continue;
        long long a=i,b=k/i;
        if(gcd(a,b)==x) ans++;
    }
    printf("%d",ans);
    return 0;
}