#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char des[100];
int vis[1000005];
ll table[10]={998244353ll,(long long)1e9+7,(long long)1e9+9,19260817ll,10000000019ll,10000002527ll,193873ll,194269ll,91815541ll,68861641ll};
vector<int> prime;

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void sel()
{
    int n=1000000;
    for(ll i=2;i<=n;i++)
        if(!vis[i])
        {
            prime.push_back(i);
            for(ll j=i*i;j<=n;j+=i) vis[j]=1;
        }
}

void gen1(int n)
{
    printf("%d",prime[n]);
}

void gen2()
{
    printf("%d",prime[rnd(100,prime.size()-1)]);
}

void gen3(int i)
{
    printf("%lld",table[i]);
}

int main()
{
    srand(time(NULL));
    sel();
    for(int i=1;i<=90;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        if(i<=10) gen3(i-1);
        else if(i<=70) gen1(i-11);
        else gen2();
        fclose(stdout);
    }
    return 0;
}
