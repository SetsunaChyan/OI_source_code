#include <bits/stdc++.h>
using namespace std;

int n,siz[1000005],gao[1000005];
vector<int> e[1000005],ans;

void dfs(int now,int fa)
{
    siz[now]=1;
    for(auto to:e[now])
        if(to!=fa)
        {
            dfs(to,now);
            siz[now]+=siz[to];
            gao[siz[to]]++;
        }
}

int main()
{
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,1);
    for(int i=1;i<n-1;i++)
        if(n%(i+1)==0)
        {
            int tmp=0,d=n/(i+1);
            for(int j=d;j<=1000000;j+=d) tmp+=gao[j];
            if(tmp==i) ans.push_back(i);
        }
    ans.push_back(n-1);
    for(auto p:ans) printf("%d ",p);
    return 0;
}
