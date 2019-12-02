#include <bits/stdc++.h>
using namespace std;

int deg[100005],n,vis[100005];
vector<int> e[100005];
vector<int> ans;

int main()
{
    scanf("%d",&n);
    for(int i=0,a,b,c;i<n-2;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        e[a].push_back(b),e[b].push_back(a);
        e[a].push_back(c),e[c].push_back(a);
        e[b].push_back(c),e[c].push_back(b);
        deg[a]+=2,deg[b]+=2,deg[c]+=2;
    }
    int st,ed,ged;
    for(int i=1;i<=n;i++)
        if(deg[i]==2) ed=st,st=i;
    for(auto to:e[ed]) if(deg[to]==4) ged=to;
    vis[ged]=vis[ed]=1;
    for(int i=0;i<n-2;i++)
    {
        int mm=0x3f3f3f3f,num;
        ans.push_back(st);
        vis[st]=1;
        for(auto to:e[st]) if(!vis[to]) deg[to]--;
        for(auto to:e[st])
            if(deg[to]<mm&&!vis[to]) mm=deg[to],num=to;
        st=num;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]) ans.push_back(i);
    ans.push_back(ged);
    ans.push_back(ed);
    for(auto p:ans) printf("%d ",p);
    return 0;
}

/*
5
1 2 3
2 3 4
3 4 5
*/
