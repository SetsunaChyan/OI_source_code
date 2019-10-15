#include <bits/stdc++.h>
using namespace std;

int cnt[100005],qaq,n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
        if(cnt[x]==1) qaq++;
        if(qaq==n)
        {
            printf("1");
            for(int i=1;i<=n;i++)
            {
                cnt[i]--;
                if(cnt[i]==0) qaq--;
            }
        }else printf("0");
    }
    return 0;
}
