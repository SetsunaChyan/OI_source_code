#include <cstdio>
#include <cstring>

char s[1000],s1[1000],s2[1000];
int err=0,pos=0;

inline int abs(int x){return x<0?-x:x;}

void check()
{
    int l=strlen(s),l1=strlen(s2);
    if(l!=l1) err=99;
    if(l1<l) l=l1;
    for(int i=0;i<l;i++)
        if(s[i]!=s2[i]) {err++;pos=i+1;}
}

int main()
{
    memset(s,0,sizeof(s));
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    scanf("%s%s",s,s1);
    for(int i=0,j=0;i<strlen(s1);j++,i++)
    {
        if(s1[i]=='+')
        {
            s2[j]='\0';
            break;
        }
        else if(s1[i]=='-') {j-=2;if(j<0)j=-1;}
        else s2[j]=s1[i];
    }
    check();
    if(err==0)
        printf("YES\n");
    else if(err==1)
        printf("NO\n%d",pos);
    else
        printf("NO\n");
    //printf("\n%s",s2);
    return 0;
}