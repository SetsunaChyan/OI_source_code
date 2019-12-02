#include <bits/stdc++.h>
using namespace std;

int n,m,a[1005][1005],b[1005][1005],posx[1005*1005],posy[1005*1005];
int len[1005][1005],st[1005],w[1005],cur,ans;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=m+1;j++)
            a[i][j]=-1,b[i][j]=-2;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&b[i][j]);
            posx[b[i][j]]=i;
            posy[b[i][j]]=j;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int x=a[i][j];
            if(a[i][j+1]==b[posx[x]][posy[x]+1]) len[i][j]=1;
        }
    int cur;
    for(int i=1;i<=n;i++)
    {
        cur=0;
        for(int j=m;j>=1;j--)
            if(len[i][j]) len[i][j]=++cur;
            else cur=1,len[i][j]=1;
    }
    /*for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            printf("%d%c",len[i][j]," \n"[j==m]);*/
    for(int j=1;j<=m;j++)
    {
        cur=0;
        for(int i=1;i<=n;i++)
        {
            int x=a[i][j];
            if(len[i][j]>st[cur])
            {
                st[++cur]=len[i][j],w[cur]=1;
            }
            else
            {
                int width=0;
                while(st[cur]>len[i][j])
                {
                    width+=w[cur];
                    ans=max(ans,width*st[cur]);
                    cur--;
                }
                st[++cur]=len[i][j],w[cur]=width+1;
            }
            //gao
            if(a[i+1][j]!=b[posx[x]+1][posy[x]])
            {
                int width=0;
                while(cur)
                {
                    width+=w[cur];
                    ans=max(ans,width*st[cur]);
                    cur--;
                }
                cur=0;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
