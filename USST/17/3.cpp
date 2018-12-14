#include <cstdio>
#include <cstring>

int n,m[10000];
char s[10000];

bool check()
{
    int i;
    for(i=0;i<10000;i++)
        if(m[i]!=0) break;
    for(int j=1;i<10000;i++,j++)
        if(m[i]!=m[10000-j]) return false;
    return true;
}

void add()
{
    int temp[10000],i;
    memset(temp,0,sizeof(temp));
    for(i=0;i<10000;i++)
        if(m[i]!=0) break;
    for(int j=10000-1;i<10000;i++,j--)
        temp[j]=m[i];
    for(i=10000-1;i>0;i--)
    {
        m[i]+=temp[i];
        m[i-1]+=m[i]/n;
        m[i]%=n;
    }
}

int main()
{
    scanf("%d%s",&n,s);
    int l=strlen(s);
    memset(m,0,sizeof(m));
    for(int i=10000-l,j=0;i<10000;i++,j++)
    {
        if(s[j]>='0'&&s[j]<='9')
            m[i]=s[j]-'0';
        else
            m[i]=s[j]-'A'+10;
    }
    int flag=0;
    for(int i=0;i<=30;i++)
    {
        if(check())
        {
            flag=1;
            printf("STEP=%d",i);
            break;
        }
        add();
    }
    if(!flag) printf("Impossible!");
    return 0;
}