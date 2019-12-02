#include <bits/stdc++.h>
using namespace std;

int n,m,q;
char mp[105][105];

void solve()
{
    scanf("%d%d%d",&n,&m,&q);
    memset(mp,'.',sizeof(mp));
    while(q--)
    {
        int x1,y1,x2,y2;char c;
        scanf("%d%d%d%d%*c%c",&x1,&y1,&x2,&y2,&c);
        for(int i=x1;i<=x2;i++)
            for(int j=y1;j<=y2;j++)
                mp[i][j]=c;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            printf("%c",mp[i][j]);
        printf("\n");
    }
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

