#include <bits/stdc++.h>
using namespace std;

int b[100][100],a[100][100],n,m;
vector<pair<int,int> > op;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&b[i][j]);
    for(int i=0;i<n-1;i++)
        for(int j=0;j<m-1;j++)
        {
            if(b[i][j]&&b[i][j+1]&&b[i+1][j]&&b[i+1][j+1])
            {
                op.emplace_back(i+1,j+1);
                a[i][j]=1;
                a[i+1][j]=1;
                a[i][j+1]=1;
                a[i+1][j+1]=1;
            }
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]!=b[i][j])
            {
                printf("-1");
                return 0;
            }
    printf("%d\n",op.size());
    for(auto b:op)
        printf("%d %d\n",b.first,b.second);
    return 0;
}
