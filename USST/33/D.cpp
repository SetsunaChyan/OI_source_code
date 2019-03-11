#include <cstdio>
#include <memory.h>

int ans=-1,n,a[26*26];
char s[105],b[2];

int main()
{
    memset(a,0,sizeof(a));
    scanf("%d %s",&n,s);
    for(int i=0;i<n-1;i++)
        a[(s[i]-'A')*26+s[i+1]-'A']++;
    for(int i=0;i<26*26;i++)
        if(a[i]>ans)
        {
            ans=a[i];
            b[0]=i/26+'A';
            b[1]=i%26+'A';
        }
    printf("%c%c",b[0],b[1]);
    return 0;
}