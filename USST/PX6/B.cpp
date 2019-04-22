#include <cstdio>
#include <cstring>
#include <memory.h>

int dp[1005][1005],l1,l2;
char a[1005],b[1005];

inline int max(int a,int b){return a>b?a:b;}

int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%s%s",a,b);
    l1=strlen(a),l2=strlen(b);
    for(int i=1;i<=l1;i++)
        for(int j=1;j<=l2;j++)
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    printf("%d",dp[l1][l2]);
    return 0;
}