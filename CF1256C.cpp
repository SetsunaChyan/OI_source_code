#include <bits/stdc++.h>
using namespace std;

int n,m,d,c[1005],ans[1005],sum;

int main()
{
    scanf("%d%d%d",&n,&m,&d);
    for(int i=0;i<m;i++) scanf("%d",c+i),sum+=c[i];
    int cur=0,last=0;
    for(int i=1;i<=n;i++)
    {
        if(ans[i]) continue;
        if(last+d<=i||n-i+1<=sum)
        {
            if(cur==m)
            {
                printf("NO\n");
                return 0;
            }
            for(int j=i;j<i+c[cur];j++) ans[j]=cur+1;
            sum-=c[cur];
            last=i+c[cur]-1;
            cur++;
        }
    }
    printf("YES\n");
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}
/*
10 10 1
1 1 1 1 1 1 1 1 1 1
*/
