#include <cstdio>
#include <cstring>

int n;
char a[20005];

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%s%d",a,&n);
        int l=strlen(a);
        for(int i=0;i<n;i++)
            for(int j=0;j<l-i;j++)
                if(a[j]>a[j+1])
                {
                    for(int k=j;k<l-i;k++)
                        a[k]=a[k+1];
                    break;
                }
        printf("%s\n",a);
    }
    return 0;
}