#include <bits/stdc++.h>
using namespace std;
typedef long double ldb;
typedef struct STATE
{
    int x,y,z;
    STATE(){}
    STATE(int x,int y,int z):x(x),y(y),z(z){}
}piii;
int n,m,k,life;
piii from[105][105][105];
ldb dp[105][105][105];
int main()
{
    n=100,m=5,k=6,life=1;
    memset(dp,0,sizeof(dp));
    dp[1][0][life]=1;
    for(int i=1;i<n;i++)
        for(int j=1;j<=life;j++)

    return 0;
}
