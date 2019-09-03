#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;

const ll _1e16=10000000000000000ll;
ll tp,low,p,q;
char s[20];

void print(ll x)
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) print(x/10);
     putchar(x%10+'0');
}

void solve(ll a,ll b,ll c,ll d)
{
    if(a==0)
    {
        p=1,q=d/c+1;
        return;
    }
    else if(a>=b)
    {
        solve(a%b,b,c-(a/b)*d,d);
        p+=(a/b)*q;
        return;
    }
    else if(c>d)
    {
        p=1,q=1;
        return;
    }
    else
    {
        solve(d,c,b,a);
        swap(p,q);
    }
}

int main()
{
    scanf("%s",s);
    ll tmp=0;
    for(int i=2;i<=16;i++)
        tmp*=10,tmp+=s[i]-'0';
    low=10*tmp-5;
    tp=10*tmp+5;
    if(tmp==0)
    {
        printf("0 1");
        return 0;
    }
    if(_1e16/__gcd(low,_1e16)<=1e9)
    {
        print(low/__gcd(low,_1e16));
        putchar(' ');
        print(_1e16/__gcd(low,_1e16));
        return 0;
    }
    solve(low/__gcd(low,_1e16),_1e16/__gcd(low,_1e16),tp/__gcd(tp,_1e16),_1e16/__gcd(tp,_1e16));
    print(p);
    putchar(' ');
    print(q);
    return 0;
}
