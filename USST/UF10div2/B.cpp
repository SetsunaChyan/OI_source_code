#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k;
char s[100005];

int main()
{
    scanf("%d%d%s",&n,&k,s+1);
    for(int i=1;i<n&&k;i++)
    {
        if(i+2<=n&&i%2==1&&s[i]=='4'&&s[i+2]=='7'&&(s[i+1]=='4'||s[i+1]=='7'))
        {
            if(k&1)
                if(s[i+1]=='4') s[i+1]='7'; else s[i+1]='4';
            printf("%s",s+1);
            return 0;
        }
        if(s[i]=='4'&&s[i+1]=='7'&&i%2==0)
        {
            s[i]='7';k--;
            continue;
        }
        else if(s[i]=='4'&&s[i+1]=='7'&&i%2==1)
        {
            s[i+1]='4';k--;
            continue;
        }
    }
    printf("%s",s+1);
    return 0;
}
