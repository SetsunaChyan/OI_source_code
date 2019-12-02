#include <bits/stdc++.h>
using namespace std;

int fa[300005],n,ans[300005],a[300005],head[300005],mx;
deque<int> q;
vector<int> v[300005];

int _find(int x)
{
    if(x==fa[x]) return x;
    ans[x]+=ans[fa[x]];
    return fa[x]=_find(fa[x]);
}

void _merge(int x,int y)
{
    x=_find(x);
    y=_find(y);
    if(x!=y) fa[x]=y;
}

bool cmp(int a,int b)
{
    if(a&1) return b<=a/2;
    return b<a/2;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i),fa[i]=fa[i+n]=fa[i+n+n]=i,mx=max(mx,a[i]);
    int flag=1;
    for(int i=0;i<n;i++)
        if(cmp(mx,a[i])) flag=0;
    if(flag)
    {
        for(int i=0;i<n;i++) printf("-1 ");
        return 0;
    }
    int N=3*n;
    for(int i=0;i<N;i++)
    {
        int num=i%n,now=a[i%n],cnt=0;
        v[num].clear();
        while(!q.empty()&&cmp(a[q.front()],now))
        {
            ans[q.front()]=q.size();
            q.pop_front();
        }
        while(!q.empty()&&a[q.back()]<now)
        {
            cnt++;
            //ans[q.back()]=max(ans[q.back()],cnt);
            //_merge(q.back(),num);
            v[num].push_back(q.back());
            q.pop_back();
        }
        reverse(v[num].begin(),v[num].end());
        v[num].push_back(num);
        q.push_back(num);
    }
    for(int i=0;i<n;i++)
        for(int j=v[i].size()-2;j>=0;j--)
            ans[v[i][j]]=max(ans[v[i][j]],ans[v[i][j+1]]+1);
    for(int i=0;i<n;i++)
        for(int j=v[i].size()-2;j>=0;j--)
            ans[v[i][j]]=max(ans[v[i][j]],ans[v[i][j+1]]+1);
    for(int i=0;i<n;i++)
        for(int j=v[i].size()-2;j>=0;j--)
            ans[v[i][j]]=max(ans[v[i][j]],ans[v[i][j+1]]+1);
    for(int i=0;i<n;i++)
        for(int j=v[i].size()-2;j>=0;j--)
            ans[v[i][j]]=max(ans[v[i][j]],ans[v[i][j+1]]+1);

    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    //printf("\n");
    //for(int i=0;i<n;i++)
    //    printf("%d ",fa[i]==i?ans[i]:ans[i]+ans[_find(i)]);
    return 0;
}
