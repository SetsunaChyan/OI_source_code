#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double qaq=5.0/3;
double a;
ll n;
char s[1000005];

void solve()
{
    scanf("%s%lf",s,&a);
    int l=strlen(s);
    if(l>=5)
        n=10000;
    else
    {
        n=0;
        for(int i=0;i<l;i++)
            n*=10,n+=s[i]-'0';
    }
    double rlast=a*5.0/3,r2;
    for(int i=1;i<n;i++)
    {
        rlast=rlast*a/(rlast+a);
        rlast=rlast*3*a/(rlast+3*a);
        rlast+=3*a;
        rlast=rlast*3*a/(rlast+3*a);
    }
    printf("%.10f\n",rlast);
    //printf("%.10f\n",qaq*a/n);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
