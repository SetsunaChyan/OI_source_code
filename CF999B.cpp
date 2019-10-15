#include <bits/stdc++.h>
using namespace std;

int n;
char s[1000],t[1000];

int main()
{
    scanf("%d%s",&n,s);
    for(int i=2;i<=n;i++)
    {
        if(n%i) continue;
        for(int j=0;j<i;j++)
            t[j]=s[j];
        for(int j=0;j<i;j++)
            s[j]=t[i-j-1];
    }
    printf("%s",s);
    return 0;
}
