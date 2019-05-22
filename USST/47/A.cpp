#include <bits/stdc++.h>
using namespace std;

char a[30],b[30];

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%s%s",a,b);
        if(a[0]=='0'&&b[0]=='0'&&strcmp(a,b)==0)
        {
            printf("true\n");
            continue;
        }
        if(a[0]=='-'&&strcmp(a+1,b)==0||b[0]=='-'&&strcmp(b+1,a)==0)
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}