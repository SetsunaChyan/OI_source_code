#include <cstdio>
#include <memory.h>

int n,vis[4][13];
int q=0,cnt=0;
char s[300005][10];

int main()
{
    memset(vis,0,sizeof vis);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=n-1;i>=0;i--)
    {
        if(q==52) break;
        int x=s[i][0]-'A';
        int y;
        if(s[i][1]>='1'&&s[i][1]<='9'||s[i][2]=='0')
        {
            if(s[i][2]=='0') y=9;
            else y=s[i][1]-'1';
        }
        else if(s[i][1]=='J')
            y=10;
        else if(s[i][1]=='Q')
            y=11;
        else
            y=12;
        if(vis[x][y]) cnt++;
        else {vis[x][y]=1;q++;}
    }
    if(q==52)
        printf("%d",52+cnt*2);
    else
        printf("-1");
    return 0;
}