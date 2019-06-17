#include <bits/stdc++.h>
using namespace std;

char s[6],mp[4]={'m','s','p','z'};
int used[4][9],flg,qaq,q,tmp[4][9];//0m 1s 2p 3z

void dfs(int x,int y)
{
    if(x==3&&y==8)
    {
        if(qaq==4&&q==1) flg=1;
        return;
    }
    int dx=x,dy=y+1,g=0,fgg;
    if(dy==9) dy=0,dx+=1;
    if(y<7&&x!=3) g=1;
    for(int i=0;i<=2;i++)
    {
        fgg=0;
        if(g&&tmp[x][y]>=i&&tmp[x][y+1]>=i&&tmp[x][y+2]>=i)
        {
            tmp[x][y]-=i,tmp[x][y+1]-=i,tmp[x][y+2]-=i;
            qaq+=i;
            fgg=1;
        }
        if(g&&!fgg) break;
        if(tmp[x][y]==3)
        {
            tmp[x][y]-=3;
            qaq++;
            dfs(dx,dy);
            tmp[x][y]+=3;
            qaq--;
        }
        else if(tmp[x][y]==2)
        {
            tmp[x][y]-=2;
            q++;
            dfs(dx,dy);
            tmp[x][y]+=2;
            q--;
        }
        else if(tmp[x][y]==0)
            dfs(dx,dy);
        if(fgg)
        {
            tmp[x][y]+=i,tmp[x][y+1]+=i,tmp[x][y+2]+=i;
            qaq-=i;
        }
        if(flg) return;
    }
}

bool check()
{
    qaq=0,q=0,flg=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<9;j++)
            tmp[i][j]=used[i][j];
    for(int i=0;i<7;i++)
        if(tmp[3][i]==1||tmp[3][i]==4) return false;
    dfs(0,0);
    /*for(int i=0;i<4;i++)
    {
        for(int j=0;j<(i==3?7:9);j++)
            printf("%d ",used[i][j]);
        printf("\n");
    }
    printf("%d %d\n\n",qaq,q);*/
    if(flg) return true;
    return false;
}

int main()
{
    while(1)
    {
        memset(used,0,sizeof(used));
        for(int i=0;i<13;i++)
        {
            if(scanf("%s",s)==EOF) return 0;
            if(s[1]=='m') used[0][s[0]-'1']++;
            else if(s[1]=='s') used[1][s[0]-'1']++;
            else if(s[1]=='p') used[2][s[0]-'1']++;
            else if(s[1]=='z') used[3][s[0]-'1']++;
        }
        for(int i=0;i<4;i++)
            for(int j=0;j<(i==3?7:9);j++)
            {
                if(used[i][j]==4) continue;
                used[i][j]++;
                //printf("%d%c\n",j+1,mp[i]);
                if(check()) printf("%d%c\n",j+1,mp[i]);
                used[i][j]--;
            }
    }
    return 0;
}

/*
1s 1s 1s 2s 2s 2s 3s 3s 3s 4s 4s 4s 5s
*/
