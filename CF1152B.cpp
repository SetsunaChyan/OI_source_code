#include <bits/stdc++.h>
using namespace std;

int n,cnt=0,a[1000];

int lowbit(int x){return x&-x;}

int main()
{
    scanf("%d",&n);
    while(lowbit(n+1)!=n+1)
    {
        cnt++;
        if(cnt&1)
        {
            int k=log2(n);
            a[cnt/2]=(k+1);
            k=1<<(k+1);
            k-=1;
            n^=k;
        }
        else n++;
    }
    printf("%d\n",cnt);
    for(int i=0;i<(cnt+1)/2;i++)
        printf("%d ",a[i]);
    return 0;
}