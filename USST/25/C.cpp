#include <cstdio>

typedef long long ll;
ll c[55][55],n,m;

ll f(ll x)
{
    ll ret=1;
    for(ll i=2;i*i<=x;i++)
        if(x%i==0)
        {
            ll k=1;
            while(x%i==0)
            {
                k++;
                x/=i;
            }
            ret*=k;
        }
    if(x!=1) ret*=2;
    return ret;
}

int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<=50;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j]);
	}
    printf("%lld",f(c[n][m]));
    return 0;
}