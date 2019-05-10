#include <bits/stdc++.h>
using namespace std;

int n,m,k,num[100],vis[10005],viss[100];
char des[100];

void gen()
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<100;i++)
    {
        int k=rand()%10000+1;
        while(vis[k]) k=rand()%10000+1;
        num[i]=k;
        vis[k]=1;
    }
    n=15498,m=5+rand()%96;
    k=num[rand()%m];
    printf("%d %d %d\n",n,m,k);
    while(n--)
    {
        memset(viss,0,sizeof(viss));
        for(int i=0;i<m;i++)
        {
            int x=rand()%100;
            while(viss[x]) x=rand()%100;
            printf("%d ",num[x]);
            viss[x]=1;
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    for(int i=6;i<=20;i++)
    {
        sprintf(des,"%d.in",i);
        freopen(des,"w",stdout);
        gen();
        fclose(stdout);
    }
    return 0;
}