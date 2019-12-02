#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,vis[50005];
struct node
{
    int x,y,z,pos;
}e[50005];
vector<int> last;
vector<pii> ans;

bool cmp(node a,node b)
{
    if(a.x==b.x&&a.z==b.z) return a.y<b.y;
    if(a.z==b.z) return a.x<b.x;
    return a.z<b.z;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z),e[i].pos=i+1;
    sort(e,e+n,cmp);
    for(int i=0;i<n-1;i++)
        if(!vis[e[i].pos]&&!vis[e[i+1].pos]&&e[i].x==e[i+1].x&&e[i].z==e[i+1].z)
            vis[e[i].pos]=vis[e[i+1].pos]=1,ans.emplace_back(e[i].pos,e[i+1].pos);
    int cur=0;
    for(int i=0;i<n;i++)
        if(!vis[e[i].pos]) e[cur++]=e[i];
    for(int i=0;i<cur-1;i++)
        if(!vis[e[i].pos]&&!vis[e[i+1].pos]&&e[i].z==e[i+1].z)
            vis[e[i].pos]=vis[e[i+1].pos]=1,ans.emplace_back(e[i].pos,e[i+1].pos);
    /*int l,r=0;
    while(r<n)
    {
        l=r;
        while(r<n&&e[r].z==e[l].z) r++;
        if(e[r].z!=e[l].z) r--;
        for(int i=l;i<r;i+=2)
            vis[i]=vis[i+1]=1,ans.emplace_back(e[i].pos,e[i+1].pos);
        r=r+1;
    }*/
    for(int i=0;i<n;i++)
        if(!vis[e[i].pos]) last.push_back(e[i].pos),vis[e[i].pos]=1;
    for(auto p:ans) printf("%d %d\n",p.first,p.second);
    for(int i=0;i<last.size();i+=2)
        printf("%d %d\n",last[i],last[i+1]);
    return 0;
}
