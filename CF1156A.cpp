#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[1000],ans=0;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        if(a[i]==2&&a[i-1]==3||a[i]==3&&a[i-1]==2||a[i]==a[i-1])
        {
            printf("Infinite");
            return 0;
        }
        if(a[i]==1&&a[i-1]==3) ans+=4;
        if(a[i]==3&&a[i-1]==1) ans+=4;
        if(a[i]==2&&a[i-1]==1) ans+=3;
        if(a[i]==1&&a[i-1]==2) ans+=3;
    }
    printf("Finite\n%d",ans);
    return 0;
}