#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,r[105];
ll sum;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",r+i);
    sort(r,r+n,greater<int>());
    for(int i=0;i<n;i++)
        if(i&1) sum-=r[i]*r[i]; else sum+=r[i]*r[i];
    printf("%.10f",sum*3.14159265358979);
    return 0;
}
