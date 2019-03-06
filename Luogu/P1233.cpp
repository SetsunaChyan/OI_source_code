#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

pair<int,int> a[5000];
int n,ans=0,vis[5000],lx,ly;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i].first=x,a[i].second=y;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            ans++;
            lx=a[i].first;
            ly=a[i].second;
        }
        else continue;
        for(int j=i+1;j<n;j++)
            if(!vis[j]&&a[j].first>=lx&&a[j].second>=ly)
            {
                vis[j]=1;
                lx=a[j].first;
                ly=a[j].second;
            }
    }
    printf("%d",ans);
    return 0;
}