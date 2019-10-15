#include <bits/stdc++.h>
using namespace std;

int n,k,ax,ay,ans,p[105][105];
char s[105][105];

void check(int x,int y)
{
    for(int i=x;i<n;i++)
    {
        if(s[i][y]=='#') break;
        if(i-x+1>=k)
        {
            for(int j=x;j<=i;j++) p[j][y]++;
            break;
        }
    }
    for(int i=x;i>=0;i--)
    {
        if(s[i][y]=='#') break;
        if(x-i+1>=k)
        {
            for(int j=x;j>=i;j--) p[j][y]++;
            break;
        }
    }
    for(int i=y;i<n;i++)
    {
        if(s[x][i]=='#') break;
        if(i-y+1>=k)
        {
            for(int j=y;j<=i;j++) p[x][j]++;
            break;
        }
    }
    for(int i=y;i>=0;i--)
    {
        if(s[x][i]=='#') break;
        if(y-i+1>=k)
        {
            for(int j=y;j>=i;j--) p[x][j]++;
            break;
        }
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            check(i,j);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(p[i][j]>ans) ans=p[i][j],ax=i,ay=j;
    printf("%d %d",ax+1,ay+1);
    return 0;
}
