#include <bits/stdc++.h>
using namespace std;

int n,f[10],flag=0;
char s[200005];

int main()
{
    scanf("%d%s",&n,s);
    for(int i=0;i<9;i++)
        scanf("%d",&f[i+1]);
    for(int i=0;i<n;i++)
    {
        if(s[i]<f[s[i]-'0']+'0'||flag&&s[i]==f[s[i]-'0']+'0')
        {
            s[i]=f[s[i]-'0']+'0';
            flag=1;
        }
        else if(flag) break;
    }
    printf("%s",s);
    return 0;
}