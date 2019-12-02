#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,val[500],ans,mp[500][500];
vector<vector<int>> e[2];

bool check(vector<int> &v,int p)
{
    int ret=val[p];
    for(auto g:v)
        if(!mp[p][g]) return false;
        else ret+=val[g];
    ans=max(ret,ans);
    return true;
}

void solve()
{
    ans=0;
    for(int i=0;i<2;i++) e[i].clear();
    for(int i=1;i<=n;i++) scanf("%d",&val[i]),ans=max(ans,val[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            mp[i][j]=0;
    for(int i=0,u,v;i<m;i++)
    {
        vector<int> t;
        scanf("%d%d",&u,&v);
        ans=max(ans,val[u]+val[v]);
        t.push_back(u),t.push_back(v);
        mp[u][v]=mp[v][u]=1;
        e[0].push_back(t);
    }
    for(int i=0;i<2;i++)
        for(auto v:e[i])
        {
            vector<int> t;
            for(int j=1;j<=n;j++)
            {
                t=v;
                if(check(v,j)&&i!=1)
                {
                    t.push_back(j);
                    e[i+1].push_back(t);
                }
            }
        }
    printf("%d\n",ans);
}

int main()
{
    while(~scanf("%d%d",&n,&m)) solve();
    return 0;
}
