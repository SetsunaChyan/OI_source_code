#include <bits/stdc++.h>
using namespace std;

char s[1000005],s1[1000005],s2[1000005];
int l;

int main()
{
    scanf("%s",s);
    int l=strlen(s);
    for(int i=0;i<l;i++)
        s1[i]=s2[i]=s[i];
    int lef=0,r=0;
    for(int i=l-1;i>0;i--)
    {
        if(s1[i]=='(') lef++; else r++;
        if(s1[i]==')'&&s1[i-1]==')'&&r-1>lef+1)
        {
            s1[i]=')';
            s1[i-1]='(';
            break;
        }
    }
    lef=0,r=0;
    for(int i=l-1;i>0;i--)
    {
        if(s2[i]=='(') lef++; else r++;
        if(s2[i]==')'&&s2[i-1]=='('&&r>lef+1)
        {
            s2[i]='(';
            s2[i-1]=')';
            int j;
            for(j=i+1;j<i+1+lef;j++) s2[j]='(';
            for(;j<l;j++) s2[j]=')';
            break;
        }
    }
    printf("%s\n%s",s1,s2);
    return 0;
}
