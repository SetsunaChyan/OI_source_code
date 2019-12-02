#include <bits/stdc++.h>
using namespace std;

int n,ans[305][305];

int main()
{
    scanf("%d",&n);
    int cur=1;
    for(int i=1;i<=n;i++)
    {
        if(i&1)
            for(int j=1;j<=n;j++)
                ans[j][i]=cur++;
        else
            for(int j=n;j;j--)
                ans[j][i]=cur++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}
