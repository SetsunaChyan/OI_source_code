#include <bits/stdc++.h>
using namespace std;

int n,m,mp;
char a[100],b[100],c[100];

void solve(int cs)
{
    scanf("%d%d",&n,&m);
    scanf("%s%s%s",a,b,c);
    mp=(a[0]-b[0]+26)%26;
    printf("Case #%d: ",cs);
    for(int i=0;i<m;i++)
        printf("%c",(c[i]-'A'+mp)%26+'A');
    printf("\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    for(int i=1;i<=_;i++) solve(i);
    return 0;
}
