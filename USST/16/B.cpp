#include <cstdio>
#include <memory.h>

int n,st[10000][300];
struct node
{
    char op[100];
    int x,y;
}p[10000];

int main()
{
    int flag=0,now=1,q=0;
    memset(st,0,sizeof(st));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s%d",p[i].op,&p[i].x);
        if(p[i].op[0]=='i') scanf("%d",&p[i].y);
    }
    while(1)
    {
        if(now==0) now=1;
        if(now>n){flag=1;break;}
        if(st[now][q]==1) break;
        st[now][q]=1;
        if(p[now].op[0]=='j')
        {
            now=p[now].x;
        }
        else if(p[now].op[0]=='a')
        {
            q=(q+p[now].x)%256;
            now++;
        }
        else if(p[now].op[0]=='i')
        {
            if(q<p[now].x) now=p[now].y; else now++;
        }
        else if(p[now].op[0]=='m')
        {
            q=(q+256-p[now].x)%256;
            now++;
        }
        else if(p[now].op[0]=='x')
        {
            q=(q^p[now].x)%256;
            now++;
        }
    }
    if(flag)
        printf("%d",q);
    else
        printf("-1");
    return 0;
}