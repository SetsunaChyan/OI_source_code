#include <bits/stdc++.h>
using namespace std;

int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},m,d,y=1;

int main()
{
    scanf("%d%d",&d,&m);
    if(m<1||m>12||d<1||d>mon[m]) return printf("Impossible"),0;
    if(m<3) m+=12,y--;
    printf("%d",(y+12+13*(m+1)/5+d)%7+1);
    return 0;
}
