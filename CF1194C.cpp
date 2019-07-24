#include <bits/stdc++.h>
using namespace std;

int cnt[26],cnt2[26];
char s[105],p[105],t[105];

void solve()
{
    memset(cnt,0,sizeof(cnt));
    memset(cnt2,0,sizeof(cnt2));
    scanf("%s%s%s",s,t,p);
    int ls=strlen(s),lt=strlen(t),lp=strlen(p),curt=0;
    for(int i=0;i<lt;i++)
        cnt2[t[i]-'a']++;
    for(int i=0;i<lp;i++)
        cnt[p[i]-'a']++;
    for(int i=0;i<ls;i++)
    {
        int flag=0;
        for(int j=curt;j<lt;j++)
            if(t[j]==s[i])
            {
                flag=1;
                cnt2[s[i]-'a']--;
                curt=j+1;
                break;
            }
        if(!flag)
        {
            printf("NO\n");
            return;
        }
    }
    for(int i=0;i<26;i++)
        if(cnt2[i]>cnt[i])
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
