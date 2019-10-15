#include <bits/stdc++.h>
using namespace std;

char a[100005],b[100005];
int l,ab,ba;

int main()
{
    scanf("%s%s",a,b);
    l=strlen(a);
    for(int i=0;i<l;i++)
        if(a[i]=='4'&&b[i]=='7') ab++;
        else if(a[i]=='7'&&b[i]=='4') ba++;
    printf("%d",max(ab,ba));
    return 0;
}
