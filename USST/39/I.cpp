#include <cstdio>

int n;
char s[300005];

int main()
{
    int cnt=0;
    scanf("%d%s",&n,s);
    if(n==1&&s[0]=='0')
    {
        printf("0");
        return 0;
    }
    for(int i=0;i<n;i++)
        cnt+='1'-s[i];
    printf("1");
    for(int i=0;i<cnt;i++) printf("0");
    return 0;
}

