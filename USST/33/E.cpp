#include <cstdio>
#include <memory.h>
#include <cstring>

int cnt[26],n,flag,l;
char s[1000005];

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%s",s);
        l=strlen(s);
        flag=0;
        for(int i=0;i<l;i++)
            cnt[s[i]-'a']++;
        for(int i=0;i<26;i++)
            if(cnt[i]==l) flag=1;
        if(flag)
        {
            printf("-1\n");
            continue;
        }
        for(int i=0;i<(l+1)/2;i++)
            if(s[i]!=s[l-i-1])
            {
                printf("%s\n",s);
                flag=1;
                break;
            }
        if(flag) continue;
        for(int i=0;i<l-1;i++)
            if(s[i]!=s[i+1])
            {
                char t=s[i];
                s[i]=s[i+1];
                s[i+1]=t;
                break;
            }
        printf("%s\n",s);
    }
    return 0;
}