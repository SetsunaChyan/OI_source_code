#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[100005],p[100005],sum,k=-1;
ll ans=1e18;
vector<int> v;
set<int> s;

void seive()
{
    for(int i=2;i<100000;i++)
        if(!p[i])
            for(int j=i<<1;j<100000;j+=i) p[j]=1;
}

int main()
{
    seive();
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i),sum+=a[i];
        if(a[i]) v.push_back(i);
    }
    if(sum==1) return printf("-1"),0;
    for(int i=2;i<=sum;i++)
        if(sum%i==0)
        {
            ll tmp2=0;
            for(int j=0;j<sum/i;j++)
            {
                ll tmp=v[j*i+(i-1)/2];
                //printf("! %lld\n",tmp);
                for(int k=0;k<i;k++) tmp2+=abs(tmp-v[j*i+k]);
            }
            //printf("! %d %lld\n",i,tmp2);
            ans=min(ans,tmp2);
        }
    printf("%lld",ans);
    return 0;
}

/*
10
1 1 1 0 0 0 0 1 1 1
*/
