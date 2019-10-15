#include <bits/stdc++.h>
using namespace std;

double r,px,py;
int n;

void get_center()
{
    double sum_x=0,sum_y=0,sum_s=0;

    for(int i=1;i<=n-2;i++)
    {
        scanf("%d%d",&x3,&y3);
        double s=((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1))/2.0;
        sum_x+=(x1+x2+x3)*s;
        sum_y+=(y1+y2+y3)*s;
        sum_s+=s;
        x2=x3;
        y2=y3;
    }
    px=sum_x/sum_s/3.0,py=sum_y/sum_s/3.0;
}

int main()
{
    int n,i;
    int x1,y1,x2,y2,x3,y3;
    scanf("%d",&n);
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    return 0;
}
