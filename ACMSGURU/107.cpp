#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    if(n<=8) printf("0");
    else if(n==9) printf("8");
    else
    {
        printf("72");
        n-=10;
        for(int i=0;i<n;i++) printf("0");
    }
    return 0;
}
