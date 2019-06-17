#include <bits/stdc++.h>
using namespace std;

int n,m,h;
char tmp[105];
struct node
{
    char s[105];
    bool ac[20];
    int p,wa[20],sol,last;
}team[1005];
struct inn
{
    int x,y,z,t;
}qaq[10005];

inline bool cmp(node a,node b)
{
    if(a.sol!=b.sol) return a.sol>b.sol;
    if(a.p!=b.p) return a.p<b.p;
    if(a.last!=b.last) return a.last<b.last;
    return true;
}

inline bool cmp2(inn a,inn b)
{
    return a.t<b.t;
}

int main()
{
    memset(team,0,sizeof(team));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",team[i].s);
        for(int j=1;j<=m;j++)
        {
            scanf("%s",tmp);
            if(tmp[0]=='0') continue;
            if(tmp[0]=='+'&&tmp[1]==0) continue;
            int k;
            sscanf(tmp+1,"%d",&k);
            team[i].wa[j]+=k;
        }
        for(int j=1;j<=m;j++)
        {
            int k;
            scanf("%d",&k);
            if(k==-1) continue;
            team[i].sol++;
            team[i].last=max(team[i].last,k);
            team[i].p+=k+20*team[i].wa[j];
            team[i].ac[j]=true;
        }
    }
    scanf("%d",&h);
    for(int i=0;i<h;i++)
        scanf("%d%d%d%d",&qaq[i].x,&qaq[i].y,&qaq[i].z,&qaq[i].t);
    sort(qaq,qaq+h,cmp2);
    for(int i=0;i<h;i++)
    {
        int x,y,z,t;
        x=qaq[i].x;
        y=qaq[i].y;
        z=qaq[i].z;
        t=qaq[i].t;
        if(team[x].ac[y]) continue;
        if(z)
        {
            team[x].sol++;
            team[x].last=max(team[x].last,t);
            team[x].p+=t+20*team[x].wa[y];
            team[x].ac[y]=true;
        }
        else
            team[x].wa[y]++;
    }
    sort(team+1,team+1+n,cmp);
    //for checking
    for(int i=2;i<=n;i++)
        if(team[i].sol==team[i-1].sol&&team[i].p==team[i-1].p&&team[i].last==team[i-1].last)
        {
            printf("QAQ");
            return 0;
        }
    //end
    for(int i=1;i<=n;i++)
        printf("%s %d %d\n",team[i].s,team[i].sol,team[i].p);
    return 0;
}
