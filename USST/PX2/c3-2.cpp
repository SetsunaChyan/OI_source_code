#include <cstdio>
#include <cstring>

int n;
long long sum=0,now=0;
char s[100005];

int main()
{
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++)
        if(s[i]=='O')
        {
            now++;
            sum+=now;
        }
        else now=0;
    printf("%lld",sum);
    return 0;
}