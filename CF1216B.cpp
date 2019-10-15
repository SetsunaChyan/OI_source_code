#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n;
pii p[10005];
vector<int> ans;
ll a;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        p[i]={x,i+1};
    }
    sort(p,p+n,greater<pii>());
    for(int i=0;i<n;i++)
    {
        a+=(long long)i*p[i].first+1;
        ans.push_back(p[i].second);
    }
    printf("%lld\n",a);
    for(auto p:ans) printf("%d ",p);
    return 0;
}

