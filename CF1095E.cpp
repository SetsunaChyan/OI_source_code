#include <cstdio>
#include <cstring>

int n,a[1000005],now=0,mm=0;
char s[1000005];
inline int max(int a,int b){return a>b?a:b;}
int main()
{
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++)
    { 
        if(s[i]=='(') now++; else now--;
        mm=max(now,mm);
        if(now<-2) now=0x3f3f3f3f;
    }
    if(now!=2&&now!=-2)
    {
        printf("0");
        return 0;
    }
    if(now==2)
    {
        printf("%d",mm-1);
        return 0;
    }
    now=mm=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]==')') now++; else now--;
        mm=max(now,mm);
        if(now<-2) now=0x3f3f3f3f;
    }
    //if(now!=-2)
    printf("%d",mm-1);
    return 0;
}