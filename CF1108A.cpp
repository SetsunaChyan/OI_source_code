#include <cstdio>

int main()
{
    int l1,l2,r1,r2,_,a,b;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        a=l1;
        if(a!=l2) b=l2;
        else if(a!=r2) b=r2;
        else 
        {
            a=r1;
            if(a!=l2) b=l2;
            else if(a!=r2) b=r2;
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}