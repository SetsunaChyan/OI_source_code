#include <bits/stdc++.h>
using namespace std;

int n,dp1[100005][2],dp2[100005][2];
char s[100005];

int main()
{
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++) s[i]-='0';
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]==1) dp2[i][1]=dp2[i+1][1]+1,dp2[i][0]=max(dp2[i+1][0],dp2[i+1][1]);
        else dp2[i][1]=dp2[i+1][1],dp2[i][0]=max(dp2[i+1][1]+1,dp2[i+1][0]+1);
    }
    if(s[0]==1) s[0]=0;
    dp1[0][0]=dp1[0][1]=1;
    for(int i=1;i<n;i++)
    {
        if(s[i]==0)
        {
            dp1[i][0]=dp1[i-1][0]+1;
            dp1[i][1]=max(dp1[i-1][1],dp1[i-1][0]);
            continue;
        }
        int flag=1;
        for(int j=i+1;j<n;j++)
        {
            int k1=dp1[i-1][0]+1+max(dp2[j][0],dp2[j][1]);
            int k2=max(dp1[i-1][0],dp1[i-1][1])+1+dp2[j][1];
            printf("QAQ %d %d\n",k1,k2);
            if(k1!=k2)
            {
                flag=0;
                break;
            }
        }
        if(flag) s[i]=0;
        if(s[i]==0) dp1[i][0]=dp1[i-1][0]+1,dp1[i][1]=max(dp1[i-1][1],dp1[i-1][0]);
        else dp1[i][0]=dp1[i-1][0],dp1[i][1]=max(dp1[i-1][0]+1,dp1[i-1][1]+1);
        //printf("%d %d %d\n",i,dp1[i][0],dp1[i][1]);
    }
    for(int i=0;i<n;i++)
        printf("%c",s[i]+'0');
    return 0;
}
