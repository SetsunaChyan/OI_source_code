#include <cstdio>

int h1,m1,h2,m2;

int main()
{
    scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
    m1+=(h2-h1)*60+m2;
    m1/=2;
    h1+=m1/60;
    m1%=60;
    printf("%02d:%02d",h1,m1);
    return 0;
}