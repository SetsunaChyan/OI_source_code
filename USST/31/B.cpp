#include <cstdio>

int a[6],n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        a[i]=25;
    for(int i=1;i<m;i++)
    {
        a[n-1]--;
        for(int j=n-1;j>0;j--)
            if(a[j]<0) {a[j]=25;a[j-1]--;}
    }
    for(int i=0;i<n;i++)
        printf("%c",a[i]+'a');

    return 0;
}