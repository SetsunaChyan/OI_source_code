#include <cstdio>
#include <cstring>

char s[1000005];

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%s",s);
        int l=strlen(s);
        for(int i=0;i<l-1;i++)
            if(s[i]=='.'&&s[i+1]=='.') putchar('C'); else putchar('D');
        putchar('\n');
    }
    return 0;
}