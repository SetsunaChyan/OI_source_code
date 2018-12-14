#include <cstdio>

int a[100005],b[100005];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(char j='A';j<='Z';j++)
        {
            int flag=1;
            for(int i=0;i<n;i++)
            {
               b[i]=a[i]^j;
               if(b[i]<'A'||b[i]>'Z') {flag=0;break;}
            }
            if(flag)
            {
                for(int i=0;i<n;i++)
                printf("%c",a[i]^j);
                break;
            }
        }
        printf("\n");
    }
    return 0;
}
