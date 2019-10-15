#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,x,y,ans=0x3f3f3f3f;
pii p[10005];
set<pii> s;

int check()
{
    int ret=0;
    for(int i=0;i<n;i++)
        if(s.find(make_pair(x-p[i].first,y-p[i].second))==s.end()) ret++;
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        p[i]=make_pair(x*2,y*2);
        s.insert(p[i]);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            x=p[i].first+p[j].first;
            y=p[i].second+p[j].second;
            ans=min(ans,check());
        }
    printf("%d\n",ans);
    return 0;
}
