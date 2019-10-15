#include <bits/stdc++.h>
using namespace std;

char s[10000];
int l;

int main()
{
    scanf("%s",s);
    l=strlen(s);
    int now=1,g=0;
    for(int i=1;i<l;i++)
    {
        if(s[i]==s[i-1]) now++; else now=1;
        g=max(g,now);
    }
    if(g>=7) printf("YES"); else printf("NO");
    return 0;
}
