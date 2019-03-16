#include <cstdio>
#include <memory.h>
#include <cstring>

int dp[300][45],v[300][300],n,k,m,len[6];
char s[300],wd[6][100],temp[30];

inline int max(int a,int b){return a>b?a:b;}

bool equal(int l,int r,int g)//[l,r]
{
    for(int i=l;i<=r;i++)
        if(s[i]!=wd[g][i-l]) return false;
    return true;
}

int cal(int l,int r)//[l,r]
{
    int ret=0;
    for(int i=l;i<=r;i++)
        for(int sel=0;sel<m;sel++)
            if(i+len[sel]-1<=r&&equal(i,i+len[sel]-1,sel))
            {
                ret++;
                break;
            }
    return ret;
}

int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) 
    {
        scanf("%s",temp);
        for(int j=0;j<20;j++)
            s[i*20+j]=temp[j];
    }
    s[20*n]=0;
    n*=20;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%s",wd[i]);
        len[i]=strlen(wd[i]);
    }
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            v[i][j]=cal(i,j);
    for(int i=0;i<n;i++)
        dp[i][0]=v[0][i];
    for(int i=1;i<k;i++)
        for(int j=i;j<n;j++)
            for(int l=i;l<=j;l++)
                dp[j][i]=max(dp[l-1][i-1]+v[l][j],dp[j][i]);
    printf("%d",dp[n-1][k-1]);
    return 0;
}