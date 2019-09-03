#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;

int vis[70005],flag[1000005],l,r,mx,mm;
vector<int> prime,pp;

void sel()
{
    memset(vis,0,sizeof(vis));
    for(int i=2;i<=70000;i++)
        if(!vis[i])
        {
            prime.push_back(i);
            for(int j=i<<1;j<=70000;j+=i) vis[j]=1;
        }
}

signed main()
{
    sel();
    while(~scanf("%d%d",&l,&r))
    {
        if(l==1) l=2;
        for(int i=0;i<=r-l;i++) flag[i]=0;
        for(int i=0;i<prime.size();i++)
        {
            int p=prime[i];
            if(p>r) break;
            ll now=l/p*p;
            if(now<l) now+=p;
            for(now+=p*(now==p);now<=r;now+=p) flag[now-l]=1;
        }
        pp.clear();mx=mm=1;
        for(int i=0;i<=r-l;i++)
            if(!flag[i]) pp.push_back(i+l);
        for(int i=1;i<pp.size();i++)
        {
            if(pp[i]-pp[i-1]>pp[mm]-pp[mm-1]) mm=i;
            if(pp[i]-pp[i-1]<pp[mx]-pp[mx-1]) mx=i;
        }
        if(pp.size()<=1)
            printf("There are no adjacent primes.\n");
        else
            printf("%d,%d are closest, %d,%d are most distant.\n",pp[mx-1],pp[mx],pp[mm-1],pp[mm]);
    }
    return 0;
}
