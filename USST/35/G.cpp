#include <cstdio>

int y,m,d,w,n;

const int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};

bool isr(int x)
{
    if(x%400==0||(x%4==0&&x%100!=0)) return true;
    return false;
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%4d%2d%2d%d%d",&y,&m,&d,&w,&n);
        w=((w-1)+n)%7+1;
        for(int i=0;i<n;i++)
        {
            d++;
            if(m==2)
            {
                if(isr(y)&&d>29) {m++;d=1;}
                else if(!isr(y)&&d>28) {m++;d=1;}
            }
            else
            {
                if(d>mon[m-1]) {m++;d=1;}
            }
            if(m>12){y++;m=1;}
        }
        printf("%d%02d%02d %d\n",y,m,d,w);
    }
    return 0;
}