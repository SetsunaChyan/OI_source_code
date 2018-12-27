#include <cstdio>
#include <cstring>

char s[100],ss[100];

int main()
{
    scanf("%s",ss);
    int l=strlen(ss),p=0;
    if(!(l&1)) p=l-1;
    for(int i=l-1;i>=0;i--)
    {
        s[i]=ss[p];
        p=l-1-p;
        if(l%2==0&&i%2==0) p--;
        if(l%2&&i%2) p++;
    }
    for(int i=0;i<l;i++)
        printf("%c",s[i]);
    return 0;
}