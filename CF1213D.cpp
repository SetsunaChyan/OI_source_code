#include <bits/stdc++.h>
using namespace std;

int n,k,cnt[200005][30],ans=0x3f3f3f3f;

int main()
{
    scanf("%d%d",&n,&k);
    int x,c;
    for(int i=0;i<n;i++)
    {
        c=0;
        scanf("%d",&x);
        cnt[x][0]++;
        while(x)
        {
            x>>=1;
            cnt[x][++c]++;
        }
    }
    for(int i=0;i<=200000;i++)
    {
        int cost=0,sel=0;
        for(int j=0;j<30;j++)
        {
            if(k-sel<=cnt[i][j])
            {
                cost+=j*(k-sel);
                sel=k;
                break;
            }
            sel+=cnt[i][j];
            cost+=j*cnt[i][j];
        }
        if(sel==k) ans=min(cost,ans);
    }
    printf("%d",ans);
    return 0;
}
