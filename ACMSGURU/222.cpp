#include <bits/stdc++.h>
using namespace std;

int n,k,c[11][11];

int main()
{
    for(int i=1;i<=10;i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    scanf("%d%d",&n,&k);
    int p=1;
    for(int i=1;i<=k;i++) p*=i;
    if(k>n) return printf("0"),0;
    printf("%d",c[n][k]*c[n][k]*p);
    return 0;
}
