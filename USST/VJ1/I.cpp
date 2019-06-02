#include <cstdio>

const int r[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
int n,m,map[1001][1001];

bool dfs(int turn,int toward,int x,int y,int dx,int dy)
{
    int i;
    for(i=0;i<4;i++)
    {
        if(x+r[i][0]<=n&&x+r[i][0]>0&&y+r[i][1]<=m&&y+r[i][1]>0&&map[x+r[i][0]][y+r[i][1]]==0)
        {
            if(i!=toward)
            {
                turn++;
                if(turn>2)
                {
                    turn--;
                    continue;
                }
            }
            x+=r[i][0];y+=r[i][1];
            if(x==dx&&y==dy) return true;
            map[x][y]=-1;
            if(dfs(turn,i,x,y,dx,dy))
            {
                map[x][y]=0;
                return true;
            }
            else
            {
                map[x][y]=0;
                x-=r[i][0];y-=r[i][1];
                if(i!=toward) turn--;
            }
        }
    }
    return false;
}

int main()
{
    int q,i,j,x1,x2,y1,y2,temp;
    bool flag;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0) break;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf("%d",&map[i][j]);
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            for(j=0;j<4;j++)
            {
                temp=map[x2][y2];
                flag=map[x1][y1]==map[x2][y2]&&map[x1][y1]!=0;
                map[x2][y2]=0;
                flag=flag&&dfs(0,j,x1,y1,x2,y2);
                map[x2][y2]=temp;
                if(flag) break;
            }
            if(flag) printf("YES\n"); else printf("NO\n");
        }
    }

    return 0;
}
