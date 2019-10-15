#include <bits/stdc++.h>
using namespace std;

int n,a,b,c;

int main()
{
    scanf("%d%d%d%d",&n,&a,&b,&c);
    n--;
    if(n==0) return printf("0"),0;
    printf("%d",min(a,b)+(n-1)*min(a,min(b,c)));
    return 0;
}
