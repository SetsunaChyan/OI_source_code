#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

int dp[20005],m,n;
struct node
{
    int num,dli;
}a[55];

inline bool cmp(node a,node b){return a.dli>b.dli;}
inline int min(int a,int b){return a<b?a:b;}

void zero_one(int v,int cnt)
{
    for(int i=m;i>=v;i--)
        dp[i]=min(dp[i-v]+cnt,dp[i]);
}

int main()
{
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&a[i].dli,&a[i].num);
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
    {
        int k=1,g=a[i].num;
        while(k<g)
        {
            zero_one(k*a[i].dli,k);
            g-=k;
            k<<=1;
        }
        zero_one(g*a[i].dli,g);
    }
    if(dp[m]!=0x3f3f3f3f)
        printf("%d",dp[m]);
    else
        printf("unhappy");
    return 0;
}