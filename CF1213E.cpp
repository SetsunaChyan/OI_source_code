#include <bits/stdc++.h>
using namespace std;

int n,flag;
char s1[5],s2[5],ans[5];

bool cmp(char a[],char b[])
{
    if(a[0]==b[0]&&a[1]==b[1]) return false;
    return true;
}

int main()
{
    scanf("%d",&n);
    scanf("%s%s",s1,s2);
    printf("YES\n");
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
            {
                if(i==j||j==k||i==k) continue;
                ans[0]=ans[3]=i+'a',ans[1]=j+'a',ans[2]=k+'a';
                if(cmp(&ans[0],s1)&&cmp(&ans[1],s1)&&cmp(&ans[2],s1)&&cmp(&ans[0],s2)&&cmp(&ans[1],s2)&&cmp(&ans[2],s2))
                {
                    ans[3]=0;
                    for(int i=0;i<n;i++) printf("%s",ans);
                    return 0;
                }
            }
    if(s1[0]==s2[0])
    {
        for(int i=0;i<n;i++) putchar(s1[1]);
        for(int i=0;i<n;i++) putchar(s2[1]);
        for(int i=0;i<n;i++) putchar(s1[0]);
    }
    else if(s1[1]==s2[1])
    {
        for(int i=0;i<n;i++) putchar(s1[1]);
        for(int i=0;i<n;i++) putchar(s2[0]);
        for(int i=0;i<n;i++) putchar(s1[0]);
    }
    else
    {
        int tmp='a'+'b'+'c';
        tmp-=s1[0]+s1[1];
        for(int i=0;i<n;i++) putchar(s1[0]);
        for(int i=0;i<n;i++) putchar(tmp);
        for(int i=0;i<n;i++) putchar(s1[1]);
    }
    return 0;
}
