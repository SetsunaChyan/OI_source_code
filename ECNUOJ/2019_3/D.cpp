#include <cstdio>

int ans,n,m,x1,x2,y1,y2;

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    ans=(200+x1-x2+y1-y2)%2;
    if(!ans) printf("Win"); else printf("Lose");
    return 0;
}