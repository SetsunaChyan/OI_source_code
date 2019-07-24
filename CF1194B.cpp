#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[50005],b[50005];
vector<char> sb[50005];
char s[50005];

void solve()
{
    scanf("%d%d",&n,&m);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++)
    {
        sb[i].clear();
        sb[i].shrink_to_fit();
    }
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        for(int j=0;j<m;j++)
        {
            sb[i].push_back(s[j]);
            if(s[j]=='.') b[j]++,a[i]++;
        }
    }
    int ans;
    ans=0x3f3f3f3f;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
           if(sb[i][j]=='.') ans=min(ans,a[i]+b[j]-1);
           else ans=min(ans,a[i]+b[j]);
    printf("%d\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();

    return 0;
}
