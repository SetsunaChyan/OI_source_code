#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int mv[4][2]={0,1,1,0,-1,0,0,-1};
struct STATE
{
    int x,y,cost,used;
    string s;
};
queue<STATE> q;
vector<pii> v;
int n,m,k,vis[55][55][4],sx,sy,tx,ty,flag;
string ans,viss[55][55][4];
char mp[55][55];

void bfs()
{
    STATE start,tmp;
    start.x=sx,start.y=sy,start.cost=0,start.s=string("");
    start.used=0;
    q.push(start);
    int x,y,cost,dx,dy,nc,used;
    string s;
    while(!q.empty())
    {
        x=q.front().x,y=q.front().y,cost=q.front().cost;
        s=q.front().s;
        q.pop();
        if(flag&&s.size()>ans.size())
        {
            flag=2;
            cout<<ans;
            return;
        }
        for(int i=0;i<4;i++)
        {
            dx=mv[i][0]+x,dy=mv[i][1]+y,nc=cost;
            if(dx<0||dx>=n||dy<0||dy>=m) continue;
            if(dx==sx&&dy==sy) continue;
            if(mp[dx][dy]=='T')
            {
                flag=1;
                ans=min(ans,s);
                continue;
            }
            if(mp[dx][dy]!=mp[x][y]&&cost==k) continue;
            if(mp[dx][dy]!=mp[x][y]&&!(1<<(mp[dx][dy]-'a'))) used|=1<<(mp[dx][dy]-'a');
            if(!vis[dx][dy][nc])
                for(int j=nc;j<=k;j++)
                {
                    vis[dx][dy][j]=1;
                    viss[dx][dy][j]=s+mp[dx][dy];
                }
            else if(s.size()+1>viss[dx][dy][nc].size()||s.size()+1==viss[dx][dy][nc].size()&&s+mp[dx][dy]>viss[dx][dy][nc]) continue;
            tmp.x=dx,tmp.y=dy,tmp.cost=nc,tmp.s=s+mp[dx][dy],tmp.used=nu;
            q.push(tmp);
        }
    }
}

int main()
{
    char ss[301];
    for(int i=0;i<300;i++) ss[i]='z';
    ans=string(ss);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%s",mp[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(mp[i][j]=='S') sx=i,sy=j;
            if(mp[i][j]=='T') tx=i,ty=j;
        }
    bfs();
    if(!flag) printf("-1");
    else if(flag==1) cout<<ans;
    return 0;
}
