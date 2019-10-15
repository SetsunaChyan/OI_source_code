#include <bits/stdc++.h>
using namespace std;

char s[100][100];
int n,m,f,a,c,e,ans;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            f=a=c=e=0;
            for(int k=0;k<2;k++)
                for(int l=0;l<2;l++)
                    if(s[i+k][j+l]=='f') f++;
                    else if(s[i+k][j+l]=='a') a++;
                    else if(s[i+k][j+l]=='c') c++;
                    else if(s[i+k][j+l]=='e') e++;
            if(f&&a&&c&&e) ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
