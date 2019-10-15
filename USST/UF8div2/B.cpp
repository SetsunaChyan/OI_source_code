#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll s[100005],ans;
vector<int> e[100005];

void dfs(int now,int fa,ll mx)
{
    for(auto &to:e[now])
    {
        if(to==fa) continue;
        if(s[to]!=-1&&s[to]<mx)
        {
            ans=-1;
            return;
        }
        if(s[to]==-1) dfs(to,now,mx);
        else dfs(to,now,s[to]);
        if(ans==-1) return;
        if(s[to]!=-1) ans+=s[to]-mx;
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=2,x;i<=n;i++)
        scanf("%d",&x),e[i].push_back(x),e[x].push_back(i);
    for(int i=1;i<=n;i++)
        scanf("%lld",s+i);
    if(s[1]==-1) dfs(1,1,0);
    else dfs(1,1,s[1]);
    if(s[1]!=-1&&ans!=-1) ans+=s[1];
    printf("%lld",ans);
    return 0;
}
