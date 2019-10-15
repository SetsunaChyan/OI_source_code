#include <bits/stdc++.h>
using namespace std;

int tmp[1000];
int x1[4],x2[4],y1[4],y2[4];
int mp[100][100],ans,tot;

int main()
{
    for(int i=0;i<3;i++)
    {
        scanf("%d%d%d%d",x1+i,y1+i,x2+i,y2+i);
        tmp[tot++]=x1[i];
        tmp[tot++]=x2[i];
        tmp[tot++]=y1[i];
        tmp[tot++]=y2[i];
    }
    sort(tmp,tmp+tot);
    tot=unique(tmp,tmp+tot)-tmp;
    int k;
    for(int i=0;i<3;i++)
    {
        x1[i]=lower_bound(tmp,tmp+tot,x1[i])-tmp+1;x1[i]*=2;
        y1[i]=lower_bound(tmp,tmp+tot,y1[i])-tmp+1;y1[i]*=2;
        x2[i]=lower_bound(tmp,tmp+tot,x2[i])-tmp+1;x2[i]*=2;
        y2[i]=lower_bound(tmp,tmp+tot,y2[i])-tmp+1;y2[i]*=2;
        //printf("%d %d %d %d \n",x1[i],y1[i],x2[i],y2[i]);
    }
    for(int i=x1[2];i<=x2[2];i++)
        for(int j=y1[2];j<=y2[2];j++)
            mp[i][j]=1;
    for(int i=x1[1];i<=x2[1];i++)
        for(int j=y1[1];j<=y2[1];j++)
            mp[i][j]=1;
    for(int i=x1[0];i<=x2[0];i++)
        for(int j=y1[0];j<=y2[0];j++)
            if(!mp[i][j]) ans=1;
    if(ans) printf("YES"); else printf("NO");
    return 0;
}
