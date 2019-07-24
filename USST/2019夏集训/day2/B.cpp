#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
        printf("%d\n",(int)ceil(log(n)/log(3)));
    return 0;
}
