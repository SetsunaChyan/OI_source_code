#include <cstdio>

int n,m,z=0,t1=1<<17,t2=1<<18;

int main()
{
    scanf("%d%d",&n,&m);
    if(n==2&&m==0)
    {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for(int i=0;i<n-3;i++)
    {
        m^=i;
        printf("%d ",i);
    }
    if(n==1) printf("%d",m);
    else if(n==2) printf("%d %d",m^t1,t1);
    else printf("%d %d %d",m^t1,m^t2,m^t1^t2);
    return 0;
}