#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[26][2];
char a[105],b[105];

void solve()
{
    memset(cnt,0,sizeof(cnt));
    scanf("%s%s",a,b);
    int l=strlen(a);
    for(int i=0;i<l;i++) cnt[a[i]-'a'][0]++;
    for(int i=0;i<l;i++) cnt[b[i]-'a'][1]++;
    for(int i=0;i<26;i++)
        if(cnt[i][0]&&cnt[i][1])
        {
            printf("YES\n");
            return;
        }
    printf("NO\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
