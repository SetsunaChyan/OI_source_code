#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    if(n<=2) printf("%d",n);
    else if(n==3) printf("6");
    else if(n%4==1) printf("%d",n<<1);
    else if(n%4==2) printf("%d",n);
    else if(n%4==3) printf("12");
    else printf("4");
    return 0;
}