#include <bits/stdc++.h>
using namespace std;

int k,n,a,b;
char s[1005],t[1005];

int main()
{
    scanf("%d",&k);
    scanf("%s%s",s,t);
    n=strlen(s);
    for(int i=0;i<n;i++)
        if(s[i]==t[i]) a++; else b++;
    printf("%d",2*min(a,k)+b-k);
    return 0;
}
