#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[100005],b[100005],s[100005],vis[100005],ans;
map<ll,int> m;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",a+i),m[a[i]]++;
    for(int i=0;i<n;i++)
        scanf("%lld",b+i);
    int cnt=0;
    for(int i=0;i<n;i++)
        if(m[a[i]]>1) ans+=b[i],b[i]=0,cnt++,vis[i]=1;
    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;
        for(int j=0;j<n;j++)
            if(vis[j]&&(a[i]|a[j])==a[j])
            {
                vis[j]=1,ans+=b[i],cnt++;
                break;
            }
    }
    if(cnt<=1) ans=0;
    printf("%lld",ans);
    return 0;
}
