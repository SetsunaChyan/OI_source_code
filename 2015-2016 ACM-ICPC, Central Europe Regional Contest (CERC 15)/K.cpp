#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int n;
int a[N],b[N];
vector<int> e[N];
int lk[N],rlk[N];
bool vis[N];

bool dfs(int x)
{
    for(auto y:e[x])
    {
        if(!vis[y])
        {
            vis[y]=1;
            if(lk[y]==0||dfs(lk[y]))
            {
                lk[y]=x;
                rlk[x]=y;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)
        scanf("%d",&b[i]);

    return 0;
}
