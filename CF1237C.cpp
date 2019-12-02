#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n,vis[2005];
struct node
{
    ll x,y,z;
    int pos;
}e[2005];
vector<pii> ans;

ll dis(int i,int j)
{
    return (e[i].x-e[j].x)*(e[i].x-e[j].x)+(e[i].y-e[j].y)*(e[i].y-e[j].y)+(e[i].z-e[j].z)*(e[i].z-e[j].z);
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld%lld%lld",&e[i].x,&e[i].y,&e[i].z),e[i].pos=i+1;
    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;
        ll mm=0x3f3f3f3f3f3f3f3fll,num=0;
        for(int j=i+1;j<n;j++)
            if(!vis[j]&&dis(i,j)<=mm) mm=dis(i,j),num=j;
        vis[i]=vis[num]=1,ans.emplace_back(e[i].pos,e[num].pos);
    }
    for(auto p:ans) printf("%d %d\n",p.first,p.second);
    return 0;
}
