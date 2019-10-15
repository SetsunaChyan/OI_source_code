#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[1000005];
int cnt[26];
int n;

void solve()
{
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++)
        cnt[s[i]-'a']++;
    for(int i=0;i<cnt['n'-'a'];i++) printf("1 ");
    for(int i=0;i<cnt['z'-'a'];i++) printf("0 ");
}

int main()
{
    solve();
    return 0;
}
