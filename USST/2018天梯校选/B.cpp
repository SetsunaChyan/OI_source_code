#include <cstdio>

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        int n,j=0;
        long long i=0;
        scanf("%d",&n);
        while(i<n)
        {
            j++;
            i+=j;
        }
        printf("%c\n",'a'+(j-i+n-1)%26);
    }
    return 0;
}