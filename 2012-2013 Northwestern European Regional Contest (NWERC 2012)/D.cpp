#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int mp[10][7]=
{
    1,1,1,0,1,1,1,
    0,1,1,0,0,0,0,
    1,1,0,1,1,0,1,
    1,1,1,1,1,0,0,
    0,1,1,1,0,1,0,
    1,0,1,1,1,1,0,
    1,0,1,1,1,1,1,
    1,1,1,0,0,0,0,
    1,1,1,1,1,1,1,
    1,1,1,1,1,1,0
};
int n,vis[4][10];
vector<int> cor[10];
vector<pii> ans;
char s[55][55];

bool check(int h,int m,int delta)
{
    m+=delta;
    h+=m/60,m%=60;
    h%=24;
    for(int i=0;i<4;i++)
    {
        int t=s[delta][i]-'0',my;
        if(i==0) my=h/10;
        else if(i==1) my=h%10;
        else if(i==2) my=m/10;
        else if(i==3) my=m%10;
        for(int j=0;j<7;j++)
        {
            if(mp[my][j]&&!mp[t][j]&&vis[i][j]==2) return false;
            if(mp[t][j]&&vis[i][j]==1) return false;
            if(mp[t][j]&&!mp[my][j]) return false;
            if(!mp[t][j]&&mp[my][j]) vis[i][j]=1;
            if(mp[t][j]&&mp[my][j]) vis[i][j]=2;
        }
    }
    return true;
}

void solve()
{
    ans.clear();
    for(int i=0;i<n;i++)
        scanf("%s",s[i]),s[i][2]=s[i][3],s[i][3]=s[i][4];
    for(int h=0;h<24;h++)
        for(int m=0;m<60;m++)
        {
            memset(vis,0,sizeof(vis));
            int flag=1;
            for(int i=0;i<n;i++)
                if(!check(h,m,i)) flag=0;
            if(flag) ans.emplace_back(h,m);
        }
    if(ans.size()!=0)
    {
        for(auto p:ans)
            printf("%02d:%02d ",p.first,p.second);
        printf("\n");
        return;
    }
    printf("none\n");
}

int main()
{
    /*cor[0].push_back(1);cor[0].push_back(7);
    cor[3].push_back(1);cor[3].push_back(7);
    cor[4].push_back(1);
    cor[6].push_back(5);
    cor[7].push_back(1);
    for(int i=0;i<=9;i++)
        cor[8].push_back(i),cor[i].push_back(i);
    cor[9].push_back(1);cor[9].push_back(3);cor[9].push_back(4);cor[9].push_back(5);cor[9].push_back(7);*/
    while(~scanf("%d",&n)) solve();
    return 0;
}

/*
3
23:59 23:59 00:00
5
00:59 01:00 01:01 01:02 01:03
*/
