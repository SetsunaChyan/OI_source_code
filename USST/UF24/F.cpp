#include <bits/stdc++.h>
using namespace std;

int t,sx,sy,ex,ey,ans=0x3f3f3f3f,x,y;
char c[4][2]={'S','E','S','W','N','E','N','W'},s[100005];

int main()
{
    scanf("%d%d%d%d%d",&t,&sx,&sy,&ex,&ey);
    scanf("%s",s);
    ex-=sx,ey-=sy;
    for(int i=0;i<4;i++)
    {
        int x=0,y=0;
        for(int j=0;j<t;j++)
        {
            if(s[j]==c[i][0]||s[j]==c[i][1]) continue;
            if(s[j]=='E'&&x<ex) x++;
            else if(s[j]=='S'&&y>ey) y--;
            else if(s[j]=='W'&&x>ex) x--;
            else if(s[j]=='N'&&y<ey) y++;
            if(x==ex&&y==ey) ans=min(ans,j+1);
        }
    }
    if(ans==0x3f3f3f3f) printf("-1");
    else printf("%d",ans);
    return 0;
}
