#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,m,a[10005],ans;
vector<pii> p[10005];

int main()
{
    scanf("%d%d%d",&n,&m,&a[0]);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=0;i<=n;i++)
    {
        for(int j=2;j*j<=a[i];j++)
            if(a[i]%j==0)
            {
                int cnt=0;
                while(a[i]%j==0) a[i]/=j,cnt++;
                p[i].emplace_back(j,cnt);
            }
        if(a[i]>1) p[i].emplace_back(a[i],1);
    }
    for(int i=1;i<=n;i++)
        for(auto &s:p[i]) s.second*=m;
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(auto pk:p[0])
            for(auto pa:p[i])
                if(pa.first==pk.first&&pa.second>=pk.second)
                    cnt++;
        if(cnt==p[0].size()) ans++;
    }
    printf("%d",ans);
    return 0;
}
