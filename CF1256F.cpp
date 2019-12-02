#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll v1,v2;
int n,cnt[26],p1[26],p2[26],vis[26];
char s[200005],t[200005];

void solve()
{
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    memset(p1,0,sizeof(p1));
    memset(p2,0,sizeof(p2));
    v1=v2=0;
    scanf("%d",&n);
    scanf("%s%s",s,t);
    for(int i=0;i<n;i++)
        cnt[s[i]-'a']++,vis[s[i]-'a']++,cnt[t[i]-'a']--;
    for(int i=0;i<26;i++)
        if(cnt[i])
        {
            printf("NO\n");
            return;
        }
    for(int i=0;i<26;i++)
        if(vis[i]>1)
        {
            printf("YES\n");
            return;
        }
    for(int i=0;i<n;i++)
    {
        for(int j=s[i]-'a'+1;j<26;j++) v1+=p1[j];
        for(int j=t[i]-'a'+1;j<26;j++) v2+=p2[j];
        p1[s[i]-'a']++;
        p2[t[i]-'a']++;
    }
    //printf("! %lld %lld\n",v1,v2);
    if((v1-v2)&1) printf("NO\n");
    else printf("YES\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
