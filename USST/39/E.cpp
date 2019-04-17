#include <cstdio>

int x,y,dx,dy;

inline int abs(int x){return x<0?-x:x;}
inline int max(int a,int b){return a>b?a:b;}

int main()
{
    char c;
    scanf("%c%d",&c,&y);
    x=c-'a';y--;
    scanf(" %c%d",&c,&dy);
    dx=c-'a';dy--;
    int k=max(abs(dx-x),abs(dy-y));
    printf("%d\n",k);
    for(int i=0;i<k;i++)
    {
        if(x<dx)
        {
            x++;
            printf("R");
        }
        else if(x>dx)
        {
            x--;
            printf("L");
        }
        if(y<dy)
        {
            y++;
            printf("U");
        }
        else if(y>dy)
        {
            y--;
            printf("D");
        }
        printf("\n");
    }
    return 0;
}