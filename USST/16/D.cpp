#include <cstdio>
#include <cstring>
#include <memory.h>

char s[400000],s1[400000];
int l,ap[26],maxn=0;

int main()
{
    memset(ap,0,sizeof(ap));
    scanf("%s",s);
    l=strlen(s);
    for(int i=0;i<l;i++)
    {
        ap[s[i]-'a']++;
        if(ap[s[i]-'a']>maxn) maxn=ap[s[i]-'a'];
    }
    if(maxn*2>l)
    {
        printf("impossible\n");
        return 0;
    }
    for(int i=0;i<=l;i++) s1[i]=s[i];
    for(int i=0;i<l;i++)
    {
        int flag=0;
        if(s1[i]!=s[i]) continue;
        for(int j=i+1;j<l;j++)
        {
            if(s1[i]!=s1[j]&&s1[j]!=s[i]&&s1[i]!=s[j])
            {
                char t=s1[i];
                s1[i]=s1[j];
                s1[j]=t;
                flag=1;
                break;
            }
        }
        if(flag) continue;
        for(int j=0;j<i-1;j++)
        {
            if(s1[i]!=s1[j]&&s1[j]!=s[i]&&s1[i]!=s[j])
            {
                char t=s1[i];
                s1[i]=s1[j];
                s1[j]=t;
                break;
            }
        }
    }
    s1[l]='\0';
    printf("%s",s1);
    return 0;
}