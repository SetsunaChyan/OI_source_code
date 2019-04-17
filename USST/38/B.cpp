#include <cstdio>

int main()
{
    int n,cnt=0;
    unsigned int p;
    scanf("%d",&n);
    p=n;
    while(p)
    {
        cnt+=p&1;
        p>>=1;
    }
    printf("%d",cnt);
    return 0;
}

