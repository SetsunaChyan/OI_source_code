#include <bits/stdc++.h>
using namespace std;

int n,m,ans,mp[300][300];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x+y) ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
