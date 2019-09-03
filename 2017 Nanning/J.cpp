#include <bits/stdc++.h>
using namespace std;

int n,cnt[3];

void solve()
{
    int x;
    cnt[0]=cnt[1]=cnt[2]=0;
    scanf("%d",&n);
    for(int i=0;i<n*2;i++)
        scanf("%d",&x),cnt[x%3]++;
    if(cnt[0]>n)
    {
        printf("NO\n");
        return;
    }
    if(cnt[0]==2)
    {
        if(cnt[1]&1)
        {
            printf("YES\n");
            return;
        }
        else
        {
            printf("NO\n");
            return;
        }
    }
    if((cnt[0]==0||cnt[0]==1)&&(cnt[1]==0||cnt[2]==0))
    {
        printf("YES\n");
        return;
    }
    else if(cnt[0]==0||cnt[0]==1)
    {
        printf("NO\n");
        return;
    }
    printf("YES\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
