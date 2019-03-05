#include <cstdio>
#include <memory.h>

const int D[5][5]={{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}};
int dp[105][105],g1[105],g2[105],l1,l2;
char s1[105],s2[105];

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

int main()
{
    memset(dp,0xc0,sizeof(dp));
    scanf("%d %s %d %s",&l1,s1,&l2,s2);
    for(int i=0;i<l1;i++)
        if(s1[i]=='A') g1[i+1]=0;
        else if(s1[i]=='C') g1[i+1]=1;
        else if(s1[i]=='G') g1[i+1]=2;
        else if(s1[i]=='T') g1[i+1]=3;
    for(int i=0;i<l2;i++)
        if(s2[i]=='A') g2[i+1]=0;
        else if(s2[i]=='C') g2[i+1]=1;
        else if(s2[i]=='G') g2[i+1]=2;
        else if(s2[i]=='T') g2[i+1]=3;
    dp[0][0]=0;
    for(int i=1;i<=l1;i++)
        dp[i][0]=dp[i-1][0]+D[g1[i]][4];
    for(int i=1;i<=l2;i++)
        dp[0][i]=dp[0][i-1]+D[4][g2[i]];
    for(int i=1;i<=l1;i++)
        for(int j=1;j<=l2;j++)
        {
            dp[i][j]=max(dp[i][j],dp[i-1][j]+D[g1[i]][4]);
            dp[i][j]=max(dp[i][j],dp[i][j-1]+D[4][g2[j]]);
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+D[g1[i]][g2[j]]);
        }
    printf("%d",dp[l1][l2]);
    return 0;
}