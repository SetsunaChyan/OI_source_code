#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,x;
vector<int> a;
unordered_map<int,int> m;

void solve()
{
    x*=1e7;
    a.clear();m.clear();
    for(int i=0,y;i<n;i++)
        scanf("%d",&y),a.push_back(y),m[y]++;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++)
    {
        auto it=lower_bound(a.begin(),a.end(),x-a[i]);
        if(it==a.end()) continue;
        if(a[i]+*it==x&&a[i]==*it)
        {
            if(m[a[i]]>1)
            {
                printf("yes %d %d\n",a[i],x-a[i]);
                return;
            }
            continue;
        }
        if(a[i]+*it==x)
        {
            printf("yes %d %d\n",a[i],x-a[i]);
            return;
        }
    }
    printf("danger\n");
}

int main()
{
    while(~scanf("%d%d",&x,&n))
        solve();
    return 0;
}
