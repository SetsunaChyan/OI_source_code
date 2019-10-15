#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

char s[10][10];
int l,qaq[10][10][10],ans;

void bfs()
{
    queue<pii> q;
    q.emplace(0,0);
    while(!q.empty())
    {
        pii p=q.front();q.pop();
        if(p.second==8)
        {
            ans=1;
            return;
        }
        if(p.first&&qaq[p.second+1][7][p.first-1]==0&&qaq[p.second][7][p.first-1]==0) q.emplace(p.first-1,p.second+1);
        if(qaq[p.second+1][7][p.first]==0&&qaq[p.second][7][p.first]==0) q.emplace(p.first,p.second+1);
        if(p.first<7&&qaq[p.second+1][7][p.first+1]==0&&qaq[p.second][7][p.first+1]==0) q.emplace(p.first+1,p.second+1);
    }
}


int main()
{
    for(int i=0;i<8;i++)
        scanf("%s",s[i]);
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(s[i][j]=='S') qaq[0][i][j]=1;
    for(int i=1;i<9;i++)
        for(int j=1;j<8;j++)
            for(int k=0;k<8;k++)
                if(qaq[i-1][j-1][k]) qaq[i][j][k]=1;
    bfs();
    if(ans) printf("WIN"); else printf("LOSE");
    return 0;
}
