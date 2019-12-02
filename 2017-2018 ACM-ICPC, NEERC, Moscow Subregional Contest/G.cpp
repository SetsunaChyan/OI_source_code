#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,r[505][505],c[505][505];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d%d",&r[i][j],&c[i][j]);
    for(int i=0;i<n;i++)
    {
        ll sum=0;
        for(int j=0;j<m;j++)
            sum+=c[i][j];
        if(sum!=0)
        {
            printf("No");
            return 0;
        }
    }
    for(int j=0;j<m;j++)
    {
        ll sum=0;
        for(int i=0;i<n;i++)
            sum+=r[i][j];
        if(sum!=0)
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}
