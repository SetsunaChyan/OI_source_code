#include <cstdio>
#include <cstring>

char s[100005];

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%s",s);
        int l=strlen(s);
        if(l%4)
        {
            printf("No\n");
            continue;
        }
        int flag=0;
        for(int i=0;i<l;i+=4)
            if(s[i]!='2'||s[i+1]!='0'||s[i+2]!='5'||s[i+3]!='0')
            {
                flag=1;
                break;
            }
        if(flag) printf("No\n");
        else printf("Yes\n");
    }
    return 0;  
}