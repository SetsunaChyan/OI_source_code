#include <bits/stdc++.h>
using namespace std;
int n,m,l;
char s[2005],t[2005],a[200005];
int main()
{
    scanf("%d %[^\n]%d",&n,s,&m);
    bool c=0;
    while(m--)
    {
        scanf("%s",t);
        if(strlen(t)==1)
            a[l++]=c?t[0]-'a'+'A':t[0];
        else if(t[0]=='C')
            c=!c;
        else if(t[0]=='B')
            --l,l=max(l,0);
        else
            a[l++]=' ';
        //a[l]=0;
        //puts(a);
    }
    a[l]='\0';
    puts(strcmp(a,s)?"Incorrect":"Correct");
    return 0;
}
