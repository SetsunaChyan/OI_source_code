#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
char s[300005];

int main()
{
    scanf("%d%s",&n,s);
    int l=strlen(s);
    for(int i=0;i<l-1;i++)
        if(s[i]>s[i+1])
        {
            printf("YES\n%d %d",i+1,i+2);
            return 0;
        }    
    printf("NO");
    return 0;
}