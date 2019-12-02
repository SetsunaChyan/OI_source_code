#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[105];
int mp[105][105],n,m,p[105];

int main()
{
    memset(mp,-1,sizeof(mp));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) mp[i][i]=0;
    for(int i=0,x,y;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        if(x>y) swap(x,y);
        mp[y][x]=1,mp[x][y]=0;
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(mp[i][j]!=-1) continue;
            mp[i][j]=1,mp[j][i]=0;
        }
    for(int i=1,s;i<=n;i++)
    {
        s=1;
        for(int j=1;j<=n;j++) s+=mp[i][j];
        p[i]=n-s+1;
    }
    p[++n]=0x3f3f3f3f;dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        int mx=0;
        for(int j=i-1;j>=0;j--)
            if(p[j]>=mx&&p[j]<p[i])
            {
                mx=max(p[j],mx);
                dp[i]+=dp[j];
            }
    }
    printf("%lld",dp[n]);
    return 0;
}

/*
4 2
2 3
2 4

5 7
2 5
1 5
3 5
2 3
4 1
4 3
4 2

7 7
5 6
2 3
6 7
2 7
3 1
7 5
7 4

5 6
1 3
4 5
1 4
2 3
1 2
1 5

*/
