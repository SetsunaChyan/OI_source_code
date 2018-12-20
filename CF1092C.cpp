#include <cstdio>
#include <cstring>
#include <memory.h>

int n,k=0,f[101][2];
char s[200][101],suf[101],pre[101],temp[101],ans[205];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<2*n-2;i++)
    {
        scanf("%s",s[i]);
        if(strlen(s[i])==n-1)
        {
            if(k)
                strcpy(pre,s[i]);
            else
                strcpy(suf,s[i]);
            k++;
        }
    }
    k=0;
    for(int i=0;i<n-1;i++)
        temp[i]=pre[i];
    for(int i=1;i<n-1;i++)
        if(temp[i]!=suf[i-1]) k=1;
    temp[n-1]=suf[n-2];
    if(k)
    {
        for(int i=0;i<n-1;i++)
            temp[i]=suf[i];
        temp[n-1]=pre[n-2];
    }
    for(int i=0;i<2*n-2;i++)
    {
        int l=strlen(s[i]);
        k=0;
        for(int j=0;j<l;j++)
            if(s[i][j]!=temp[j]) {k++;break;}
        if(k)
            for(int j=n-l;j<n;j++)
                if(s[i][j-n+l]!=temp[j]) {k++;break;}
        if(k==2)
        {
            for(int j=0;j<n-1;j++)
                temp[j]=suf[j];
            temp[n-1]=pre[n-2];
            break;
        }
    }
    memset(f,0,sizeof(f));
    for(int i=0;i<2*n-2;i++)
    {
        int l=strlen(s[i]);
        k=0;
        for(int j=0;j<l;j++)
            if(s[i][j]!=temp[j]) {k++;break;}
        for(int j=n-l;j<n;j++)
            if(s[i][j-n+l]!=temp[j]) {k+=2;break;}
        if(k==0)
            ans[i]='A';
        else if(k==1)
        {
            ans[i]='S';
            f[l][1]=1;
        }
        else
        {
            ans[i]='P';
            f[l][0]=1;
        }
    }
    for(int i=0;i<2*n-2;i++)
    {
        int l=strlen(s[i]);
        if(ans[i]=='A')
            if(f[l][0]) {printf("S");f[l][1]=0;} else {printf("P");f[l][0]=1;}
        else printf("%c",ans[i]);
    }
    return 0;
}