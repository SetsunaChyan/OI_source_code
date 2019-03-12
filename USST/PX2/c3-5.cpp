#include <cstdio>

int n,l,r,flag=0;
char s[3005];

int main()
{
    scanf("%d %s",&n,s);
    for(l=0;l<n&&s[l]==s[0];l++);
    for(r=0;r<n&&s[n-1-r]==s[n-1];r++);
    if(s[0]==s[n-1])
        if(l==n) printf("%d",(n+1)*n/2); else printf("%d",(l+1)*(r+1));
    else
        printf("%d",l+r+1);
    return 0;
}