#include <bits/stdc++.h>
using namespace std;

char s[1000];
int n;

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        int k=999;
        scanf("%d%s",&n,s);
        for(int i=0;i<n;i++)
            if(s[i]=='8')
            {
                k=i;
                break;
            }
        if(k+11<=n) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}