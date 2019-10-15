#include <bits/stdc++.h>
using namespace std;

int n,cnt[1000005],ans;

int main()
{
    scanf("%d",&n);
    for(int i=0,x;i<n;i++)
    {
        scanf("%d",&x);
        cnt[x]++;
    }
    for(int i=1000000;i>=1;i--)
    {
        int num=0;
        for(int k=i;k<=1000000;k+=i) num+=cnt[k];
        if(num>1)
        {
            printf("%d",i);
            return 0;
        }
    }
    return 0;
}
