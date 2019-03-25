#include <cstdio>

const int mv[4][2]={0,1,1,0,0,-1,-1,0};

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        int n,x=0,y=0,now=0;
        char s[50];
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            if(s[0]=='L') now=(now+3)%4;
            else if(s[0]=='R') now=(now+1)%4;
            else if(s[0]=='B') now=(now+2)%4;
            else
            {
                int g;
                scanf("%d",&g);
                x+=mv[now][0]*g;
                y+=mv[now][1]*g;
            }
        }
        printf("%d %d\n",x,y);
    }


    return 0;
}