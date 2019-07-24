#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(0));
    int n=10;
    freopen("1002test.in","w",stdout);
    printf("%d\n",n);
    for(int i=0;i<n;i++)
        printf("%d ",rand()%30+1);
    printf("\n");
    fclose(stdout);
    return 0;
}
