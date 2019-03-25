#include <cstdio>

int n,ans=0;
long long a[1000005];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(int i=0,j=n-1;i<j;)
    {
        if(a[i]<a[j])
        {
            a[i+1]+=a[i];
            ans++;
            i++;
        }
        else if(a[i]>a[j])
        {
            a[j-1]+=a[j];
            ans++;
            j--;
        }
        else 
        {
            i++;
            j--;
        }
    }
    printf("%d",ans);
    return 0;
}