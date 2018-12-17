#include <cstdio>
#include <cstring>
#include <algorithm>
#include <memory.h>

using namespace std;

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        char s[1005];
        int cnt[26];
        memset(cnt,0,sizeof(cnt));
        scanf("%s",s);
        int l=strlen(s);
        for(int i=0;i<l;i++)
            cnt[s[i]-'a']++;
        int k=0;
        for(int i=0;i<26;i++)
            if(cnt[i]) k++;
        if(k==1)
        {
            printf("-1\n");
            continue;
        }
        sort(s,s+l);
        printf("%s\n",s);
    }
    return 0;
}