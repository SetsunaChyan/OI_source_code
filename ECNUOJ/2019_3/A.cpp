#include <cstdio>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("%d %d %d\n",3*i+2,3*i+3,3*i+4);
    }
    return 0;
}