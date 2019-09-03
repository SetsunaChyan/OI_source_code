#include <bits/stdc++.h>
using namespace std;

char s[1000];

void solve()
{
    scanf("%s",s);
    if(s[0]=='z')
    {
        s[0]='b';
        printf("%s\n",s);
        return;
    }
    int i,l=strlen(s);
    for(i=0;i<l;i++)
        if(s[i]!='y') break;
    if(i<l&&s[i]=='z') s[i]='b';
    printf("%s\n",s);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
