#include <bits/stdc++.h>
using namespace std;

int a[3][3];
vector<int> b;

int main()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<3;i++)
        sort(a[i],a[i]+3),b.push_back(a[i][1]);
    sort(b.begin(),b.end());
    printf("%d",b[1]);
    return 0;
}
