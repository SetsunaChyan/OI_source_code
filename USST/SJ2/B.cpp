#include <cstdio>
#include <memory.h>
#include <cstring>

int vis[256];
char s[10005],s2[10005];

int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%[^\n]",s);
    scanf(" %[^\n]",s2);
    int l=strlen(s2);
    for(int i=0;i<l;i++)
        vis[s2[i]]=1;
    l=strlen(s);
    for(int i=0;i<l;i++)
        if(!vis[s[i]]) printf("%c",s[i]);
    printf("\n");
    return 0;
}