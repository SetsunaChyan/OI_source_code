#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+50;
char s[maxn];
int n;
long long a1=0,a2=0;

int main()
{
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++)
        if(s[i]==s[0]) a1++; else break;
    for(int i=n-1;i>=a1;i--)
        if(s[i]==s[n-1]) a2++; else break;
    if(s[0]==s[n-1])
        printf("%lld",(a1+1)*(a2+1)%998244353);
    else
        printf("%lld",(a1+a2+1)%998244353);
    return 0;
}
