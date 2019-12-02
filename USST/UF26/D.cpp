#include <bits/stdc++.h>
using namespace std;

int n,c[55],a=-0x3f3f3f3f,b=0x3f3f3f3f,sum,ans;

void dfs(int now,int na)
{
    ans=max(a,ans);
    if(na<a||na>b) return;
    a=max(a,na),b=min(na,b);
    if(now==n) return;
    dfs(now+1,na+c[now]);
    dfs(now,na+c[now]);
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&c[i]),sum+=c[i];
    dfs(0,0);
    printf("%d %d",ans,sum-ans);
    return 0;
}
