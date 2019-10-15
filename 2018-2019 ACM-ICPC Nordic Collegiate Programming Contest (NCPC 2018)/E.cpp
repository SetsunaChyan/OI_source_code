#include <bits/stdc++.h>
using namespace std;

int a[5],ans;

void dfs(int now)
{
    if(now==5)
    {
        if(a[4]>=a[3]&&a[3]>=a[2]&&a[2]>=1&&a[1]>=a[0]) ans++;
        return;
    }
    for(int i=0;i<=6;i++)
        a[now]=i,dfs(now+1);
}

int main()
{
    dfs(0);
    printf("%d",ans);
    return 0;
}
