#include <bits/stdc++.h>
using namespace std;

int rk[]={0,3,1,2};
char cc[]={'D','A','C','B'};

int main()
{
    int x,a,b,c;
    scanf("%d",&x);
    a=x+1,b=x+2;
    if(rk[x%4]>rk[a%4]&&rk[x%4]>rk[b%4])
        printf("0 %c",cc[x%4]);
    else if(rk[a%4]>rk[b%4]&&rk[a%4]>rk[x%4])
        printf("1 %c",cc[a%4]);
    else
        printf("2 %c",cc[b%4]);
    return 0;
}
