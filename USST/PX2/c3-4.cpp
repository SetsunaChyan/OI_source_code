#include <cstdio>

double now,a;
int i;

int main()
{
    while(~scanf("%lf",&a)&&a!=0)
    {
        now=0;
        for(i=0;now<a;i++,now+=(double)1.0/(i+1));
        printf("%d card(s)\n",i);
    }
    return 0;
}