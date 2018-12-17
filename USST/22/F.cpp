#include <cstdio>
#include <cstring>

char s[1005];
int n,l;

int main()
{
    scanf("%s%d",s,&n);
    int l=strlen(s);
    for(int i=0;i<n;i++)
        for(int j=0;j<l-i;j++)
        {
            if(s[j]<s[j+1]||j==l-i-1)
            {
                for(int k=j;k<l-i;k++)
                    s[k]=s[k+1];
                break;
            }
        }
    printf("%s",s);
    return 0;
}