#include <bits/stdc++.h>
using namespace std;

int len;
char s[10005],s1[10005];

bool qhd(int l,int r)
{
    while(l<r&&s[l]==s[r])
        l++,r--;
    if(l>=r) return true;
    if(s[l]>=s[r]) return true; else return false;
}

int main()
{
    scanf("%s",s);
    int l=0,r=strlen(s)-1;
    len=r+1;
    for(int i=0;i<len;i++)
    {
        if(qhd(l,r))
        {
            s1[i]=s[l];
            l++;
        }
        else
        {
            s1[i]=s[r];
            r--;
        }
    }
    s1[len]=0;
    printf("%s",s1);
    return 0;
}