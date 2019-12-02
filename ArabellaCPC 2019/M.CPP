#include <bits/stdc++.h>
using namespace std;
char s[100005];
int n,h[26];
int main()
{
    scanf("%s",s);n=strlen(s);
    for(int i=0;i<n;i++)h[s[i]-'a']++;
    for(int i=0;i<25;i++)
        h[i+1]+=h[i]/2,h[i]%=2;
    for(int i=25;i>=0;i--)
        while(h[i]--)
            putchar(i+'a');
    return 0;
}
