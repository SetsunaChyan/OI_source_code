#include <bits/stdc++.h>
using namespace std;

char s[200005];
int n,cnt;

int main()
{
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i+=2)
    {
        if(s[i]==s[i+1])
        {
            cnt++;
            if(s[i]=='a') s[i+1]='b';
            else if(s[i]=='b') s[i+1]='a';
        }
    }
    printf("%d\n%s",cnt,s);
    return 0;
}
