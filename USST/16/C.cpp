#include <cstdio>

int main()
{
    int l,p=-1;
    char s[300005];
    scanf("%d%s",&l,s);
    for(int i=0;i<l-1;i++)
        if(s[i]>s[i+1]) {p=i;break;}
    if(p==-1) p=l-1;
    for(int i=0;i<l;i++)
        if(i!=p) putchar(s[i]);
    return 0;
}