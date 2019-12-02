#include <bits/stdc++.h>
using namespace std;

int a[100005],b[100005],n,ans,t,vis[100005];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<n;i++)
        scanf("%d",b+i);
    int cur=0;
    for(int i=0;i<n;i++)
    {
        if(vis[a[i]]) continue;
        while(cur<n&&b[cur]!=a[i]) vis[b[cur]]=1,cur++,ans++;
        cur++;
    }
    printf("%d",ans);
    return 0;
}
