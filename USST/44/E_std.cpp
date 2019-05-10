#include <bits/stdc++.h>
using namespace std;

int n,m,k,ans,flag;

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    ans=0;
    for(int i=0;i<n;i++)
    {
        flag=1;
        for(int j=0;j<m;j++)
        {
            int x;
            scanf("%d",&x);
            if(x==k) flag=0;
        }
        if(flag) ans++;
    }
    printf("%d",ans);
    return 0;
}