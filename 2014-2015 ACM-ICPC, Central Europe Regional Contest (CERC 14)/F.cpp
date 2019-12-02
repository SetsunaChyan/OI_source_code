#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+9;
char s0[1000006],s1[1000006],s2[1000006];
ll to[4][4][28][28][28],dp[1000006][4];
void gao()
{
    for(int x=0;x<28;x++)
        for(int y=0;y<28;y++)
            for(int z=0;z<28;z++)
                for(char a=(x<26?(x+'a'):(x==26?'\0':'a'));a<=(x<26?(x+'a'):(x==26?'\0':'z'));a++)
                    for(char b=(y<26?(y+'a'):(y==26?'\0':'a'));b<=(y<26?(y+'a'):(y==26?'\0':'z'));b++)
                        for(char c=(z<26?(z+'a'):(z==26?'\0':'a'));c<=(z<26?(z+'a'):(z==26?'\0':'z'));c++)
                        {
                            if(a==b&&b==c)to[0][0][x][y][z]++;
                            else if(a<b&&b==c)to[0][1][x][y][z]++;
                            else if(a==b&&b<c)to[0][2][x][y][z]++;
                            else if(a<b&&b<c)to[0][3][x][y][z]++;

                            if(b<c)to[1][3][x][y][z]++;
                            else if(b==c)to[1][1][x][y][z]++;

                            if(a<b)to[2][3][x][y][z]++;
                            else if(a==b)to[2][2][x][y][z]++;

                            to[3][3][x][y][z]++;
                        }
}
int id(char c)
{
    if(!c)return 26;
    if(c=='?')return 27;
    return c-'a';
}
int main()
{
    gao();
    int _;scanf("%d",&_);
    while(_--)
    {
        scanf("%s%s%s",s0+1,s1+1,s2+1);
        int l0=strlen(s0+1),l1=strlen(s1+1),l2=strlen(s2+1),ma=max(l0,max(l1,l2));
        for(int i=l0+1;i<=ma;i++)s0[i]=0;
        for(int i=l1+1;i<=ma;i++)s1[i]=0;
        for(int i=l2+1;i<=ma;i++)s2[i]=0;
        memset(dp[0],0,sizeof(dp[0]));
        dp[0][0]=1;
        for(int i=1;i<=ma;i++)
            for(int j=0;j<4;j++)
            {
                dp[i][j]=0;
                for(int k=0;k<4;k++)
                    dp[i][j]=(dp[i][j]+to[k][j][id(s0[i])][id(s1[i])][id(s2[i])]*dp[i-1][k])%mod;//,printf("add %d %d %d %d %d=%d\n",j,k,id(s0[i]),id(s1[i]),id(s2[i]),to[j][k][id(s0[i])][id(s1[i])][id(s2[i])]);
                //printf("%d %d=%d\n",i,j,dp[i][j]);
            }
        printf("%lld\n",dp[ma][3]);
    }
    return 0;
}
