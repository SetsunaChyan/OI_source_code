#include <bits/stdc++.h>
using namespace std;

int cnt[2][30],l[2];
char s[2][100005];

void solve()
{
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<2;i++)
    {
        scanf("%s",s[i]);
        l[i]=strlen(s[i]);
        for(int j=0;j<l[i];j++)
            cnt[i][s[i][j]-'a']++;
    }
    int ans=0;
    for(int i=0;i<min(l[0],l[1]);i++)
        if(cnt[1][s[0][i]-'a']) ans++,cnt[1][s[0][i]-'a']--;
        else break;
    printf("%d\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
