#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;

const ll eps=1e-3;
int n,cnt;
ll y[1005];
vector<pli> v;
double k;

int main()
{
    scanf("%d",&n);
    if(n==2) return printf("YES"),0;
    for(int i=0;i<n;i++) scanf("%lld",y+i);
    for(int i=0;i<n;i++)
    {
        v.clear();
        cnt=n-2;
        if(i==0) k=0; else k=double(y[i]-y[0])/i;
        for(int j=1;j<n;j++) if(double(y[j]-y[0])/j==k) cnt--; else v.emplace_back(y[j],j);
        if(cnt<0) return printf("NO"),0;
        for(int j=1;j<v.size();j++) if(double(v[j].first-v[0].first)/(v[j].second-v[0].second)==k) cnt--;
        if(cnt==0) return printf("YES"),0;
    }
    cnt=n-1;
    k=double(y[2]-y[1]);
    for(int j=0;j<n;j++) if(j!=1&&double(y[j]-y[1])/abs(j-1)==k) cnt--;
    if(cnt==1) return printf("YES"),0;
    printf("NO");
    return 0;
}
