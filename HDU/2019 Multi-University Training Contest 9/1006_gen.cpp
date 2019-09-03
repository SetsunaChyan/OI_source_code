#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(0));
    freopen("qaq.in","w",stdout);
    printf("10\n");
    int n=10;
    for(int k=0;k<10;k++)
    {
        printf("%d\n",n);
        for(int i=0;i<n;i++)
            printf("%d ",10*(rand()%20+1));
        printf("\n");
    }
}
