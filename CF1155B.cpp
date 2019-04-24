#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
char s[100005];

int main()
{
    int cnt=0;
    scanf("%d%s",&n,s);
    for(int i=0;i<n-10;i++)
        if(s[i]=='8') cnt++;
    if(cnt>(n-11)/2) printf("YES\n"); else printf("NO\n");
    return 0;
}