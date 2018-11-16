#include <cstdio>

int m,n,sel[26];

void dfs(int x,int c)
{
    if(c==m)
    {
        for(int i=1;i<=c;i++)
            printf("%d ",sel[i]);
        printf("\n");
        return;
    }
    if(n-x+1<m-c) return;
    sel[c+1]=x;
    dfs(x+1,c+1);
    dfs(x+1,c);
}

int main()
{
    scanf("%d%d",&n,&m);
    dfs(1,0);
    return 0;
}
