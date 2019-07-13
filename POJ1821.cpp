#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

int n,k,dp[105][16005];
struct person
{
    int l,s,p;
}e[105];

bool cmp(person a,person b){return a.s<b.s;}

int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
        scanf("%d%d%d",&e[i].l,&e[i].p,&e[i].s);
    sort(e+1,e+k+1,cmp);
    for(int i=1;i<=k;i++)
    {
        deque<int> q;
        q.push_back(0);
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            while(!q.empty()&&q.front()+e[i].l<j) q.pop_front();
            if(!q.empty()&&e[i].s<=j) dp[i][j]=max(dp[i][j],dp[i-1][q.front()]+e[i].p*(j-q.front()));
            if(j<e[i].s)
            {
                while(!q.empty()&&dp[i-1][q.back()]-e[i].p*q.back()<dp[i-1][j]-e[i].p*j) q.pop_back();
                q.push_back(j);
            }
        }
    }
    printf("%d\n",dp[k][n]);
    return 0;
}
