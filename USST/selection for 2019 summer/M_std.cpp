#include <bits/stdc++.h>
using namespace std;

int n,ret=0;

bool check(int a,int b)
{
    for(int i=2;i<=a;i++)
        if(a%i==0&&b%i==0) return false;
    return true;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++) ret+=check(i,n);
    printf("%d",ret);
    return 0;
}