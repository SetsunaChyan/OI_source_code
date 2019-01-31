#include <cstdio>
#include <memory.h>

int n;

int main()
{
    while(~scanf("%d",&n))
    {
        int t=0,last=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            if(x<last) t++;
            last=x;
        }
        if(t<=1)
            printf("Yes\n");
        else   
            printf("No\n");
    }
    return 0;
}