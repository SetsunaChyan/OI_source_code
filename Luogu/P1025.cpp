#include <cstdio>

int n,k;

int dfs(int n,int k)
{
    if(k==1) return 1;
    if(n<0) return 0;
    return dfs(n-k,k)+dfs(n,k-1);
}
 
int main()
{
    scanf("%d%d",&n,&k);
    printf("%d",dfs(n-k,k));
    return 0;
}