#include <bits/stdc++.h>
using namespace std;

int n,cnt,mx;
char s[200005];

int main()
{
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') cnt++;
        else cnt--;
        mx=min(mx,cnt);
    }
    if(cnt==0&&mx>=-1) printf("YES");
    else printf("NO");
    return 0;
}
