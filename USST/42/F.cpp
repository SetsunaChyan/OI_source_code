#include <bits/stdc++.h>
using namespace std;

int n,m,t;
pair<int,int> row[3000005],col[3000005];

int main()
{
    memset(row,0,sizeof(row));
    memset(col,0,sizeof(col));
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=t;i++)
    {
        int op,x,c;
        scanf("%d%d%d",&op,&x,&c);
        if(op==1) row[x]=make_pair(c,i); else col[x]=make_pair(c,i);  
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(col[j].second>row[i].second)
                printf("%d",col[j].first);
            else
                printf("%d",row[i].first);
            if(j!=m) printf(" ");
        }
        printf("\n");
    }
    return 0;
}