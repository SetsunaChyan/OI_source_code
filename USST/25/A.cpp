#include <cstdio>
#include <algorithm>

using namespace std;

const int N=1e4+5;
int a[N],b[N],n,m,cnt=0,lst=-1;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+m);
    int ap=0,bp=0;
    while(ap<n&&bp<m)
    {
        if(a[ap]==b[bp])
        {
            if(cnt) printf(" ");
            cnt++;
            printf("%d",a[ap]);
            lst=a[ap];
            while(ap<n&&a[ap]==lst) ap++;
            while(bp<m&&b[bp]==lst) bp++;
        }
        else if(a[ap]<b[bp])
            ap++;
        else
            bp++;
    }
    if(cnt==0) printf("None");
    return 0;
}