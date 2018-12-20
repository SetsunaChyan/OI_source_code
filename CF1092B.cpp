#include <cstdio>
#include <algorithm>

using namespace std;

int a[105],n;

int main()
{
    int ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i+=2)
        ans+=a[i+1]-a[i];
    printf("%d",ans);
    return 0;
}