#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,l,r;
char s[300005];

int main()
{
    scanf("%s",s);
    n=strlen(s);
    l=0,r=n-1;
    while(1)
    {
        if(s[l]!=s[r]) return printf("0"),0;
        int cnt=0;
        while(s[l]==s[r]&&l<r) l++,cnt++;
        if(l==r)
        {
            if(cnt>=1) printf("%d",cnt+2);
            else printf("0");
            return 0;
        }
        while(s[r]==s[l-1]) r--,cnt++;
        if(cnt<3) return printf("0"),0;
    }
    return 0;
}
