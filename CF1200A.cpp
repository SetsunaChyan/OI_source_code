#include <bits/stdc++.h>
using namespace std;

int n;
int a[11];
char s[100005];

int main()
{
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L')
        {
            for(int j=1;j<=10;j++)
                if(!a[j])
                {
                    a[j]=1;
                    break;
                }
        }
        else if(s[i]=='R')
        {
            for(int j=10;j;j--)
                if(!a[j])
                {
                    a[j]=1;
                    break;
                }
        }
        else
            a[s[i]-'0'+1]=0;
    }
    for(int i=1;i<=10;i++)
        printf("%d",a[i]);

    return 0;
}
