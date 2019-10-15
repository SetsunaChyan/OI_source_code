#include <bits/stdc++.h>
using namespace std;

int ans,num,vis[200005],n,x;

int main()
{
    memset(vis,0x3f,sizeof(vis));
    scanf("%d",&n);
    for(int i=0,x;i<n;i++)
    {
        scanf("%d",&x);
        vis[x]=i;
    }
    ans=0x3f3f3f3f;
    for(int i=0;i<=200000;i++)
        if(vis[i]<ans) ans=vis[i],num=i;
    printf("%d",num);
    return 0;
}
