#include <bits/stdc++.h>
using namespace std;

int a,b;
char s[150][150];

int main()
{
    scanf("%d%d",&a,&b);
    for(int i=0;i<b;i++)
        scanf("%s",s[i]);
    printf("%s",s[(a-1)%b]);
    return 0;
}
