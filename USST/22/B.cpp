#include <cstdio>
#include <cstring>

int n,f[201][201];
char s[201];

int main()
{
    scanf("%s",s);
    n=strlen(s);
    memset(f,0,sizeof(f));
    for(int i=0;i<n;i++) f[i][i]=1;
    for(int i=2;i<=n;i++)
        for(int l=0;l<n-i+1;l++)
        {
            int r=l+i-1;
            f[l][r]=f[l+1][r]+f[l][r-1]-f[l+1][r-1];
            if(s[l]==s[r]) f[l][r]+=f[l+1][r-1]+1;
        }
    printf("%d",f[0][n-1]);
    return 0;
}