#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf=0x3f3f3f3f;
int l,tab[10][10][10][10],ans[10][10];
char s[2000005];

int main()
{
    memset(ans,0,sizeof(ans));
    memset(tab,0x3f,sizeof(tab));
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            for(int st=0;st<10;st++)
                for(int x=0;x<10;x++)
                    for(int y=0;y<10;y++)
                    {
                        if(x==0&&y==0) continue;
                        tab[i][j][st][(st+x*i+y*j)%10]=min(x+y,tab[i][j][st][(st+x*i+y*j)%10]);
                    }
    scanf("%s",s);
    l=strlen(s);
    for(int i=1;i<l;i++)
        for(int x=0;x<10;x++)
            for(int y=0;y<10;y++)
                if(tab[x][y][s[i-1]-'0'][s[i]-'0']!=inf&&ans[x][y]!=-1)
                    ans[x][y]+=tab[x][y][s[i-1]-'0'][s[i]-'0'];
                else
                    ans[x][y]=-1;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            printf("%d ",ans[i][j]==-1?-1:ans[i][j]-l+1);
        printf("\n");
    }
    return 0;
}
