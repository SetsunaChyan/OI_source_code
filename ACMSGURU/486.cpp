#include <bits/stdc++.h>
using namespace std;

char s1[100],s2[100];
int a,b,c1[10],c2[10];

int main()
{
    scanf("%s%s",s1,s2);
    for(int i=0;i<4;i++)
        if(s1[i]==s2[i]) a++;
        else c1[s1[i]-'0']++,c2[s2[i]-'0']++;
    for(int i=0;i<=9;i++) b+=min(c1[i],c2[i]);
    printf("%d %d",a,b);
    return 0;
}
