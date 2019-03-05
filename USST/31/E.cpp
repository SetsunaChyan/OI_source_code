#include <cstdio>

char s[100]="Wang!";
int a,b;

int main()
{
    scanf("%d%d",&a,&b);
    a+=b;
    for(int i=0;i<a;i++)
        printf("%s",s);

    return 0;
}