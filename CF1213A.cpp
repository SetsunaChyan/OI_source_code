#include <bits/stdc++.h>
using namespace std;

int n,a,b;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x&1) a++; else b++;
    }
    printf("%d",min(a,b));
    return 0;
}
