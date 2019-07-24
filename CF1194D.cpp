#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(!n)
    {
        printf("Bob\n");
        return;
    }
    if(k%3==0)
    {
        n%=k+1;
        if(n!=k&&n%3==0)
            printf("Bob\n");
        else
            printf("Alice\n");
        return;
    }
    if(n%3==0)
        printf("Bob\n");
    else
        printf("Alice\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
