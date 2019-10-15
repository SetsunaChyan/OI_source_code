#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,dis[25][25],dp[1<<21];
char s[100005];

int main()
{
    scanf("%d%d",&m,&n);
    scanf("%s",s);
    for(int i=0;i<m-1;i++)
    {
        int a=s[i]-'a',b=s[i]-'b';
        dis[max(a,b)][min(a,b)]++;
    }
    for(int i=0;i<n;i++)
        for(int mask=0;mask<(1<<n);mask++)
        {
            if(mask&(1<<i))
            {
                int cal=0;
                for(int j=0;)
                dp[mask]=min(dp[mask^(1<<i)]+cal);
            }
        }
    printf("%d",dp[(1<<n)-1]);
    return 0;
}
