#include <bits/stdc++.h>
using namespace std;

char s[1000005],s2[1000005];
int a[1000005],ans=0,now=0;

int main()
{
    scanf("%s",s);
    int la=strlen(s);
    a[0]=0;
    for(int i=1;i<la;i++)
        a[i]=a[i-1]^(s[i-1]-'0')^(s[i]-'0');
    scanf("%s",s2);
    int lb=strlen(s2);
    for(int i=0;i<lb;i++)
        now=now^(s[i]-'0')^(s2[i]-'0');
    for(int i=lb;i<la;i++)
        ans+=1^now,now^=a[i]^a[i-lb];
    printf("%d",ans+(1^now));
    return 0;
}
