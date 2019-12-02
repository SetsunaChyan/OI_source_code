#include <bits/stdc++.h>
using namespace std;

int n;
char s[100005];

void solve()
{
    scanf(" %[^\n]",s);
    n=strlen(s);
    for(int i=2;(i-1)*2<n;i++)
    {
        if((n-i+1)%i) continue;
        int flag=1,l=(n-i+1)/i;
        for(int k=l;k<n;k+=l+1)
            if(s[k]!=' ')
            {
                flag=0;
                break;
            }
        if(flag)
        {
            printf("YES\n");
            return;
        }
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
