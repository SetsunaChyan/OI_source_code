#include <bits/stdc++.h>
using namespace std;

int a[5][5];

int main()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    a[1][1]=(a[0][2]+a[2][0])/2;
    int sum=a[1][1]+a[1][2]+a[1][0];
    a[0][0]=sum-a[1][0]-a[2][0];
    a[2][2]=sum-a[0][2]-a[1][2];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            printf("%d%c",a[i][j]," \n"[j==2]);
    return 0;
}
