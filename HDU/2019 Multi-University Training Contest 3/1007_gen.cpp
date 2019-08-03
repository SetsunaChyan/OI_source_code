#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(0));
    freopen("data.in","w",stdout);
    int n=10,m=10;
    printf("1\n%d %d\n",n,m);
    for(int i=0;i<n;i++)
        printf("%d ",rand()%m+1);
    return 0;
}
