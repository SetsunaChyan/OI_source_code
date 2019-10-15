#include <bits/stdc++.h>
using namespace std;

char s[40];
int n;

void solve()
{
    memset(s,0,sizeof(s));
    scanf("%s",s);
    n=strlen(s);
    if(s[n-1]=='x'||s[n-1]=='s'||s[n-1]=='o'||n>1&&s[n-1]=='h'&&s[n-2]=='c')
        s[n]='e',s[n+1]='s';
    else if(s[n-1]=='f')
        s[n-1]='v',s[n]='e',s[n+1]='s';
    else if(n>1&&s[n-1]=='e'&&s[n-2]=='f')
        s[n-2]='v',s[n]='s';
    else if(s[n-1]=='y')
        s[n-1]='i',s[n]='e',s[n+1]='s';
    else
        s[n]='s';
    printf("%s\n",s);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
