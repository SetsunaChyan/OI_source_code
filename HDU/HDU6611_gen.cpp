#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("HDU6611data.in","w",stdout);
    printf("1\n");
    int n=2000,k=10;
    printf("%d %d\n",n,k);
    for(int i=1;i<=n;i++)
        printf("%d ",rand()%100000+1);
    return 0;
}
