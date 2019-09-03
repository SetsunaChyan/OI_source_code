#include <bits/stdc++.h>
using namespace std;

const int N=1000005;
char s[N],ans[N];
int ex[N],exnext[N],cur,n;

void get_exnext(char s[])
{
    int n=strlen(s),p=1,j,i;
    exnext[0]=n;
    for(i=0;i<n-1&&s[i]==s[i+1];i++);
    exnext[1]=i;
    for(i=2;i<n;i++)
        if(exnext[i-p]+i<p+exnext[p])
            exnext[i]=exnext[i-p];
        else
        {
            j=exnext[p]+p-i;
            if(j<0) j=0;
            while(i+j<n&&s[j]==s[i+j]) j++;
            exnext[i]=j;
            p=i;
        }
}

void exkmp(char s1[],char s2[])
{
    int l1=strlen(s1),l2=strlen(s2),p=0,i,j;
    get_exnext(s2);
    for(i=0;i<l1&&i<l2&&s1[i]==s2[i];i++);
    ex[0]=i;
    for(int i=1;i<l1;i++)
    {
        if(exnext[i-p]+i<p+ex[p])
            ex[i]=exnext[i-p];
        else
        {
            j=ex[p]+p-i;
            if(j<0) j=0;
            while(i+j<l1&&s1[i+j]==s2[j]) j++;
            ex[i]=j;
            p=i;
        }
    }
}

int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    cur=strlen(s);
    for(int i=0;i<cur;i++) ans[i]=s[i];
    for(int j=1;j<n;j++)
    {
        scanf("%s",s);
        int len2=strlen(s);
        int len=min(cur,len2),t=0;
        exkmp(&ans[cur-len],s);
        for(int i=cur-len;i<cur;i++)
            if(ex[i-cur+len]==cur-i)
            {
                t=cur-i;
                break;
            }
        for(int i=t;i<len2;i++)
            ans[cur++]=s[i];
    }
    for(int i=0;i<cur;i++)
        printf("%c",ans[i]);
    return 0;
}
