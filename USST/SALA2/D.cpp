#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[200005];
vector<ll> ans;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",a+i);
    sort(a,a+n);
    n=unique(a,a+n)-a;
    ans.push_back(a[0]);
    for(int i=0;i<n;i++)
    {
        for(ll j=1;j<=(1ll<<32);j<<=1)
        {
            int k=lower_bound(a,a+n,a[i]+j)-a;
            if(k>=n||a[k]!=a[i]+j) continue;
            k=lower_bound(a,a+n,a[i]+j+j)-a;
            if(k<n&&a[k]==a[i]+j+j)
            {
                ans.clear();
                ans.push_back(a[i]);
                ans.push_back(a[i]+j);
                ans.push_back(a[i]+j+j);
            }
            else
            {
                ans.clear();
                ans.push_back(a[i]);
                ans.push_back(a[i]+j);
            }
            if(ans.size()==3) break;
        }
        if(ans.size()==3) break;
    }
    printf("%d\n",ans.size());
    for(auto b:ans) printf("%lld ",b);
    return 0;
}
