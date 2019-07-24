#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,c,d,e,vis[100005];
vector<int> edge[100005],val[100005];

bool check(int level)
{
    memset(vis,0,sizeof(vis));
    queue<pair<int,int> > q;
    ll dis=(ll)level*d,t=(ll)level*e;
    q.push(make_pair(1,0));vis[1]=1;
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        if(p.second==t) continue;
        for(int i=0;i<edge[p.first].size();i++)
            if(!vis[edge[p.first][i]]&&val[p.first][i]<=dis)
                vis[edge[p.first][i]]=1,q.push(make_pair(edge[p.first][i],p.second+1));
    }
    return vis[n];
}

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d%d",&c,&d,&e);
    while(m--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        edge[x].push_back(y),val[x].push_back(z);
        edge[y].push_back(x),val[y].push_back(z);
    }
    int l=0,r=100000;
    while(l<r)
    {
        int mid=l+r>>1;
        if(check(mid)) r=mid; else l=mid+1;
    }
    printf("%d",c*l);
    return 0;
}

/*
5 7
1 1 1
1 2 1
1 3 5
1 4 1
2 3 2
2 4 5
3 4 3
3 5 5
*/
