#include <cstdio>
#include <cstring>

char s[256];
int k;

int main()
{
    scanf("%d%s",&k,s);
    for(int i=0;i<strlen(s);i++)
    {
        if(i!=0) printf(" ");
        printf(" ");
        for(int j=0;j<k;j++)
        {
            if(s[i]=='1'||s[i]=='4')
                printf(" ");
            else
                printf("-");
        }
        printf(" ");
    }
    printf("\n");
    for(int m=0;m<k;m++)
    {
        for(int i=0;i<strlen(s);i++)
        {
            if(i!=0) printf(" ");
            for(int j=0;j<k+2;j++)
            {
                if(j==0)
                    if(s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='8'||s[i]=='9'||s[i]=='0')
                        printf("|");
                    else
                        printf(" ");
                if(j==k+1)
                    if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
                        printf("|");
                    else
                        printf(" ");
                if(j!=0&&j!=k+1) printf(" ");
            }
        }
        printf("\n");
    }

    for(int i=0;i<strlen(s);i++)
    {
        if(i!=0) printf(" ");
        printf(" ");
        for(int j=0;j<k;j++)
        {
            if(s[i]=='1'||s[i]=='7'||s[i]=='0')
                printf(" ");
            else
                printf("-");
        }
        printf(" ");
    }
    printf("\n");

    for(int m=0;m<k;m++)
    {
        for(int i=0;i<strlen(s);i++)
        {
            if(i!=0) printf(" ");
            for(int j=0;j<k+2;j++)
            {
                if(j==0)
                    if(s[i]=='2'||s[i]=='6'||s[i]=='8'||s[i]=='0')
                        printf("|");
                    else
                        printf(" ");
                if(j==k+1)
                    if(s[i]=='1'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
                        printf("|");
                    else
                        printf(" ");
                if(j!=0&&j!=k+1) printf(" ");
            }
        }
        printf("\n");
    }

    for(int i=0;i<strlen(s);i++)
    {
        if(i!=0) printf(" ");
        printf(" ");
        for(int j=0;j<k;j++)
        {
            if(s[i]=='1'||s[i]=='4'||s[i]=='7')
                printf(" ");
            else
                printf("-");
        }
        printf(" ");
    }
    printf("\n");
    return 0;
}
