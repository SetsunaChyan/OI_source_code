#include <cstdio>

int n,x,y,k=0;

int main()
{
    scanf("%d%d%d",&n,&x,&y);
    if(x>y)
    {
        printf("%d",n);
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        int g;
        scanf("%d",&g);
        if(g<=x) k++;
    }
    printf("%d",(k+1)/2);
    return 0;
}