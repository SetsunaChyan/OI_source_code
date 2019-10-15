#include <bits/stdc++.h>
using namespace std;

int N,n,m,prex[1005][1005],sufx[1005][1005],prey[1005][1005],sufy[1005][1005];
int bitx[1005][1005],bity[1005][1005];
char mp[1005][1005],nmp[1005][1005];
struct node
{
    int x,y,len;
};
vector<node> ans;

int main()
{
    scanf("%d%d",&n,&m);
    N=max(n,m);
    for(int i=0;i<n;i++)
        scanf("%s",mp[i]);
    for(int i=0;i<n;i++)
    {
        prey[i][0]=(mp[i][0]=='*');
        for(int j=1;j<m;j++)
            if(mp[i][j]=='*') prey[i][j]=prey[i][j-1]+1;
    }
    for(int i=0;i<n;i++)
    {
        sufy[i][m-1]=(mp[i][m-1]=='*');
        for(int j=m-2;j>=0;j--)
            if(mp[i][j]=='*') sufy[i][j]=sufy[i][j+1]+1;
    }
    for(int i=0;i<m;i++)
    {
        prex[0][i]=(mp[0][i]=='*');
        for(int j=1;j<n;j++)
            if(mp[j][i]=='*') prex[j][i]=prex[j-1][i]+1;
    }
    for(int i=0;i<m;i++)
    {
        sufx[n-1][i]=(mp[n-1][i]=='*');
        for(int j=n-2;j>=0;j--)
            if(mp[j][i]=='*') sufx[j][i]=sufx[j+1][i]+1;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(mp[i][j]=='.') continue;
            int tmp=min(min(prex[i][j],sufx[i][j]),min(prey[i][j],sufy[i][j]))-1;
            if(!tmp) continue;
            bitx[i][j-tmp]++,bitx[i][j+tmp+1]--;
            bity[i-tmp][j]++,bity[i+tmp+1][j]--;
            ans.push_back({i+1,j+1,tmp});
        }
    for(int i=0;i<n;i++)
        for(int j=1;j<m;j++) bitx[i][j]+=bitx[i][j-1];
    for(int i=0;i<m;i++)
        for(int j=1;j<n;j++) bity[j][i]+=bity[j-1][i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(bitx[i][j]||bity[i][j]) nmp[i][j]='*'; else nmp[i][j]='.';
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(nmp[i][j]!=mp[i][j]) return printf("-1"),0;
    printf("%d\n",(int)ans.size());
    for(auto p:ans)
        printf("%d %d %d\n",p.x,p.y,p.len);
    return 0;
}
