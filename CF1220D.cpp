#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,qaq;
ll a[200005],start;
vector<ll> ans;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",a+i);
    for(ll i=1;i<1e18;i<<=1)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
            if(a[j]%i==0&&a[j]/i%2==1) cnt++;
        if(cnt>qaq) start=i,qaq=cnt;
    }
    for(int i=0;i<n;i++)
        if(!(a[i]%start==0&&a[i]/start%2==1)) ans.push_back(a[i]);
    printf("%d\n",(int)ans.size());
    for(auto &p:ans)
        printf("%lld ",p);
    return 0;
}
