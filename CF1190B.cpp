#include <bits/stdc++.h>
using namespace std;

char s[6],mp[4]={'m','s','p','z'};
int used[4][9],flg,qaq,q,tmp[4][9];//0m 1s 2p 3z

void dfs(int x,int y)
{
    if(x==3&&y==0) return;
    int dx=x,dy=y+1;
    if(dy==9) dy=0,dx+=1;
    if(y<7&&tmp[x][y]>=1&&tmp[x][y+1]>=1&&tmp[x][y+2]>=1)
    {
        flg=1;
        return;
    }
    if(tmp[x][y]>=3)
    {
        flg=1;
        return;
    }
    else
        dfs(dx,dy);
    if(flg) return;
}

bool check()
{
    flg=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<9;j++)
            tmp[i][j]=used[i][j];
    dfs(0,0);
    if(flg) return true;
    return false;
}

int main()
{
        memset(used,0,sizeof(used));
        for(int i=0;i<3;i++)
        {
            if(scanf("%s",s)==EOF) return 0;
            if(s[1]=='m') used[0][s[0]-'1']++;
            else if(s[1]=='s') used[1][s[0]-'1']++;
            else if(s[1]=='p') used[2][s[0]-'1']++;
            else if(s[1]=='z') used[3][s[0]-'1']++;
        }
        if(check())
        {
            printf("0");
            return 0;
        }
        for(int i=0;i<3;i++)
            for(int j=0;j<9;j++)
            {
                if(used[i][j]==4) continue;
                used[i][j]++;
                if(check())
                {
                    printf("1");
                    return 0;
                }
                used[i][j]--;
            }
        printf("2");
        return 0;
}

/*
1s 1s 1s 2s 2s 2s 3s 3s 3s 4s 4s 4s 5s
*/
