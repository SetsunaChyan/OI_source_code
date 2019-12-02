#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,a[10][4],t[10][4],ans,cnt[10],b[10][4];
map<int,int> mp;

void solve()
{
    ans=0x3f3f3f3f;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<4;j++)
            scanf("%1d",&a[i][j]);
    for(int i=0;i<4;i++)
    {
        mp.clear();
        memset(cnt,0,sizeof(cnt));
        int p=0;
        for(int j=0;j<n;j++)
        {
            mp[a[j][0]*1000+a[j][1]*100+a[j][2]*10+a[j][3]]++;
            cnt[a[j][i]]++;
            for(int k=0;k<4;k++) t[j][k]=a[j][k];
        }
        for(int j=0;j<n;j++)
        {
            if(mp[t[j][0]*1000+t[j][1]*100+t[j][2]*10+t[j][3]]<=1) continue;
            p++;
            mp[t[j][0]*1000+t[j][1]*100+t[j][2]*10+t[j][3]]--;
            for(int k=0;k<10;k++)
                if(!cnt[k])
                {
                    t[j][i]=k;
                    cnt[k]++;
                    break;
                }
            mp[t[j][0]*1000+t[j][1]*100+t[j][2]*10+t[j][3]]++;
        }
        if(p<ans)
        {
            ans=p;
            for(int j=0;j<n;j++)
                for(int k=0;k<4;k++) b[j][k]=t[j][k];
        }
    }
    printf("%d\n",ans);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
            printf("%d",b[i][j]);
        printf("\n");
    }
}

int main()
{
    int _=1;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

/*
10
10
1111
1111
1111
1111
1111
1111
1111
1111
1111
1111
*/
