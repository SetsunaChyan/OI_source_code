#include <bits/stdc++.h>
using namespace std;

int n,sl,sr,wenl,wenr;
char s[200005];

int main()
{
    scanf("%d%s",&n,s);
    for(int i=0;i<n/2;i++)
        if(s[i]=='?') wenl++;
        else sl+=s[i]-'0';
    for(int i=n/2;i<n;i++)
        if(s[i]=='?') wenr++;
        else sr+=s[i]-'0';
    if(wenl<wenr)
    {
        swap(wenl,wenr);
        swap(sl,sr);
    }
    wenl-=wenr;
    wenl>>=1;
    if(sr-sl==9*wenl) printf("Bicarp");
    else printf("Monocarp");
    return 0;
}
