#include <cstdio>

int n,root,son[26][2];

void dfs(int now)
{
    printf("%c",now+'a');
    if(son[now][0]!='*'-'a') dfs(son[now][0]);
    if(son[now][1]!='*'-'a') dfs(son[now][1]);
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char x,l,r;
        scanf(" %c%c%c",&x,&l,&r);
        son[x-'a'][0]=l-'a';
        son[x-'a'][1]=r-'a';
        if(i==0) root=x-'a';
    }
    dfs(root);
    return 0;
}