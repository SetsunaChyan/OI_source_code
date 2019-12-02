#include <bits/stdc++.h>
using namespace std;

void dfs(int x)
{
    if(x==0) return;
    dfs(x-1);
}

int main()
{
    dfs(510510);
    //freopen("j.in","w",stdout);
    //printf("510510\n");//997920
    //for(int i=1;i<510510;i++)
        //printf("%d %d\n",i,i+1);
    return 0;
}
