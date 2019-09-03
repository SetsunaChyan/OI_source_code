#include <bits/stdc++.h>
using namespace std;

int n,a[150005],vis[150005],cnt;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(a[i]>1&&!vis[a[i]-1]) a[i]--;
        if(vis[a[i]]) a[i]++;
        if(!vis[a[i]]) vis[a[i]]=1,cnt++;
    }
    printf("%d",cnt);
    return 0;
}
