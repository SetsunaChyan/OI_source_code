#include <bits/stdc++.h>
using namespace std;

int n;

void wa()
{
    if(n<=5)
    {
        printf("-1\n");
        return;
    }
    printf("1 2\n2 3\n3 4\n2 5\n");
    for(int i=6;i<=n;i++)
        printf("3 %d\n",i);
}

void cor()
{
    for(int i=1;i<n;i++)
        printf("%d %d\n",i,i+1);
}

int main()
{
    scanf("%d",&n);
    wa();
    cor();
    return 0;
}
