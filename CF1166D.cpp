#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int _;
ll a,b,k;


int main()
{
    printf("%lld",1ll<<50);
    scanf("%d",&_);
    while(_--)
    {
        scanf("%lld%lld%lld",&a,&b,&k);
        int flag=0;
        for(int i=0;i<=48;i++)
        {
            ll m=b/(1<<i)-a;
            if(1<=m&&m<=k)
            {
                flag=1;
                printf("debug %lld\n",m);
                printf("%d %lld ",i+2,a);
                for(int j=0;j<i;j++)
                    printf("%lld ",(1<<j)*(a+m));
                printf("%lld\n",b);
                break;
            }
        }
        if(!flag) printf("-1\n");
    }
    return 0;
}