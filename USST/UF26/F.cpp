#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,cnt;
double sum;
vector<int> e[100005];

void dfs(int now,int fa,int dep,double p)
{
    int son=0;
    for(auto to:e[now])
        if(to!=fa) son++;
    for(auto to:e[now])
    {
        if(to==fa) continue;
        dfs(to,now,dep+1,p/son);
    }
    if(son==0) sum+=p*dep;
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
    dfs(1,1,0,1);
    printf("%.10f",(double)sum);
    return 0;
}
