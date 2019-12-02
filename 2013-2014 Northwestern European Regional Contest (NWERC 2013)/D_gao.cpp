#include <bits/stdc++.h>
using namespace std;

int a[10000],ans;

void dfs(int now)
{
    if(now==7)
    {
        int flag=1;
        for(int i=0;i<6;i++)
            if(a[i+1]<a[i]) flag=0;
        if(flag) ans++;
        return;
    }
    for(int i=1;i<=7;i++)
        a[now]=i,dfs(now+1);
}

int main()
{
    dfs(0);
    printf("%d",ans);
    return 0;
}
