#include <bits/stdc++.h>
using namespace std;

char s[1<<22];
int l,qaq,qaq2;

void solve()
{
    scanf("%s",s);
    l=strlen(s);qaq=qaq2=0;
    for(int i=0;i<l;i++)
        if(s[i]=='^') qaq++;
    qaq2=l-qaq+1;
    if(qaq2&1) qaq2=-1; else qaq2=1;
    printf("%d\n",(qaq&1)?l-qaq+1+qaq2:l-qaq+1);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
