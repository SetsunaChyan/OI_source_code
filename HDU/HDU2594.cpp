#include <cstdio>
#include <cstring>

const int N=50005;
char s1[N],s2[N];
int ex[N],exnext[N],ans,l1,l2;

inline int max(int a,int b){return a>b?a:b;}

void get_exnext(char s[N])
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

void exkmp(char s1[N],char s2[N])
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
    while(~scanf("%s %s",s1,s2))
    {
        l1=strlen(s1);l2=strlen(s2);
        ans=0;
        exkmp(s2,s1);
        for(int i=0;i<l2;i++) 
            if(ex[i]+i==l2) ans=max(ans,ex[i]);
        for(int i=0;i<ans;i++) printf("%c",s1[i]);
        if(ans) printf(" ");
        printf("%d\n",ans);
    }

    return 0;
}