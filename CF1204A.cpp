#include <bits/stdc++.h>
using namespace std;

char s[1005];
int l;

int main()
{
    scanf("%s",&s);
    l=strlen(s);
    int flag=0,ans=0;
    for(int i=l-1;i>0;i--)
    {
        if(i%2) ans++;
        if(s[i]=='1') flag=1;
    }
    if(l%2==1&&flag) ans++;
    printf("%d",ans);
    return 0;
}
