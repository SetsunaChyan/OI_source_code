#include <bits/stdc++.h>
using namespace std;

int n,k,n1;

int main()
{
    scanf("%d%d%d",&n,&k,&n1);
    int qaq=n/n1+(n%n1!=0);
    qaq*=qaq;
    if(k<qaq) printf("NO");
    else printf("YES");
    return 0;
}
