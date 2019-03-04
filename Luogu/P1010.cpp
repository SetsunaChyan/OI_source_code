#include <cstdio>

int n;

void dfs(int x)
{
    int g=0,k=15;
    while(k>=0)
    {
        if(x&(1<<k))
        {
            if(g) printf("+");
            printf("2");
            if(k==0) printf("(0)");
            else if(k!=1)
            {
                printf("(");
                dfs(k);
                printf(")");
            }
            g++;
        }
        k--;
    }
}

int main()
{
    scanf("%d",&n);
    dfs(n);
    return 0;
}