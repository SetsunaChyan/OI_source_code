#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[100005];
ll sum=0;
double b[100005];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&b[i]);
        a[i]=floor(b[i]);
        sum+=a[i];
    }
    sum=-sum;
    for(int i=0;i<n;i++)
        if(sum&&floor(b[i])!=b[i]) printf("%d\n",a[i]+1),sum--; else printf("%d\n",a[i]);
    return 0;
}
