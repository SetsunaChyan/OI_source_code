#include <cstdio>
#include <cstring>

const char tp[3]={'R','G','B'};
char s[200005];
int n,ans=0;

int main()
{
    scanf("%d %s",&n,s);
    for(int i=1;i<n;i++)
        if(s[i]==s[i-1])
        {
            ans++;
            for(int j=0;j<3;j++)
                if(tp[j]!=s[i-1]&&(i==n-1||tp[j]!=s[i+1])) s[i]=tp[j];
        }
    printf("%d\n%s",ans,s);
    return 0;
}