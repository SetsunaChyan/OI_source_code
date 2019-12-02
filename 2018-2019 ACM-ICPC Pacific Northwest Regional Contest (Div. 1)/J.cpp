#include <bits/stdc++.h>
using namespace std;
int n,a[1005],s;
int main()
{
    scanf("%d%d",&n,&s);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    int x=*max_element(a,a+n);
    printf("%d\n",(x*s+999)/1000);
    return 0;
}
