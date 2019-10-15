#include <bits/stdc++.h>
using namespace std;

const double PI=3.14159265358979;
int n,r;

int main()
{
    scanf("%d%d",&n,&r);
    double x=sin(PI/n);
    printf("%.10f",(double)r*x/(1-x));
    return 0;
}
