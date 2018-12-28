#include <cstdio>
#include <cstring>

int l;
char s[100];

int main()
{
    scanf("%d%s",&l,s);
    for(int i=0,t=1;i<l;i+=t,t++)
        printf("%c",s[i]);
    return 0;
}