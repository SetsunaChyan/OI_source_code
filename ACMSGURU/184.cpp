#include <bits/stdc++.h>
using namespace std;

int p,m,c,k,r,v;

int main()
{
    scanf("%d%d%d%d%d%d",&p,&m,&c,&k,&r,&v);
    printf("%d",min(min(p/k,m/r),c/v));
    return 0;
}
