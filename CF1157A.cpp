#include <bits/stdc++.h>
using namespace std;

set<int> s;
int n,cnt=0;

int f(int x)
{
    x++;
    while(x%10==0) x/=10;
    return x;
}

int main()
{
    scanf("%d",&n);
    while(s.find(n)==s.end())
    {
        s.insert(n);
        n=f(n);
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}