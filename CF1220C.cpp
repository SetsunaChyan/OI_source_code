#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[500005];
int n,pre[500005],suf[500005];

void solve()
{
    scanf("%s",s);
    n=strlen(s);
    pre[0]=s[0];suf[n-1]=s[n-1];
    for(int i=1;i<n;i++)
        pre[i]=min(pre[i-1],(int)s[i]);
    printf("Mike\n");
    for(int i=1;i<n;i++)
    {
        if(pre[i-1]<s[i]) puts("Ann"); else puts("Mike");
    }
}

int main()
{
    solve();
    return 0;
}
