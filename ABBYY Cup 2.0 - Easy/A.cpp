#include <bits/stdc++.h>
using namespace std;

int b[105][105],n,ans;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        b[n/2][i]=b[i][n/2]=b[i][i]=b[n-i-1][i]=1;
    for(int i=0,x;i<n;i++)
        for(int j=0;j<n;j++)
        {
            scanf("%d",&x);
            if(b[i][j]) ans+=x;
        }
    printf("%d",ans);
    return 0;
}
