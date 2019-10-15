#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            if((j+i)&1) printf("W"); else printf("B");
        printf("\n");
    }
    return 0;
}
