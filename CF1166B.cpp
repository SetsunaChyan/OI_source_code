#include <bits/stdc++.h>
using namespace std;

int k;
const char vow[5]={'a','e','i','o','u'};

int main()
{
    scanf("%d",&k);
    for(int i=5;i<=k;i++)
    {
        if(k%i||k/i<5) continue;
        int n=i,m=k/i;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                printf("%c",vow[(i+j)%5]);
        return 0;
    }
    printf("-1");
    return 0;
}