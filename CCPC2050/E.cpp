#include <cstdio>
#include <cstring>

int a,b,w;
char s[1000005];

//wa

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        int ans=0;
        a=b=w=0;
        scanf("%s",s);
        int l=strlen(s);
        for(int i=0;i<l;i++)
        {
            if(s[i]=='A') a++;
            else if(s[i]=='B') b++;
            else if(s[i]=='?') w++;
            if(a+w-b>1&&a+w>=11)
            {
                ans++;a=b=w=0;
                continue;
            }
            if(b+w-a>1&&b+w>=11)
            {
                ans++;a=b=w=0;
                continue;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}