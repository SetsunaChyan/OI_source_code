#include <bits/stdc++.h>
using namespace std;

int x,y,z,a,b,c;

int main()
{
    scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
    if(a<x) return printf("NO"),0;
    a-=x;
    a+=b;
    if(a<y) return printf("NO"),0;
    a+=c-y;
    if(a<z) return printf("NO"),0;
    printf("YES");
    return 0;
}
