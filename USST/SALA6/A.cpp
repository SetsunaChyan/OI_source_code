#include <bits/stdc++.h>
using namespace std;

int n,s1,s2;

int main()
{
    scanf("%d",&n);
    for(int i=0,x;i<n;i++)
        scanf("%d",&x),s1+=x;
    for(int i=0,x;i<n;i++)
        scanf("%d",&x),s2+=x;
    if(s1>=s2) printf("Yes"); else printf("No");
    return 0;
}
