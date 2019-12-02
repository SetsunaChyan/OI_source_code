#include <bits/stdc++.h>
using namespace std;
int k,b,bb;
int main()
{
    scanf("%d%d",&k,&bb);

    for(b=1;b<=bb;b++)
    {
        printf("%d: ",b);
        int ans=0;
        for(int i=1;i*k<(1<<b);i++)
            //printf("%d %d\n",i*k,__builtin_popcount(i*k)),
            ans+=__builtin_popcount(i*k);
        printf("%d\n",ans);
    }
    return 0;
}
