#include <cstdio>
#include <cstring>
#include <algorithm>

int a[6];
struct node
{
    char s[10];
    int num;
}modu[26]=
{
    {"one",1},
    {"two",4},
    {"three",9},
    {"four",16},
    {"five",25},
    {"six",36},
    {"seven",49},
    {"eight",64},
    {"nine",81},
    {"ten",0},
    {"eleven",21},
    {"twelve",44},
    {"thirteen",69},
    {"fourteen",96},
    {"fifteen",25},
    {"sixteen",56},
    {"seventeen",89},
    {"eighteen",24},
    {"nineteen",61},
    {"twenty",0},
    {"a",1},
    {"both",4},
    {"another",1},
    {"first",1},
    {"second",4},
    {"third",9}
};

bool cmp(int a,int b)
{
    return a<b;
}

int main()
{
    char s[255];
    int k=0;
    for(int i=0;i<6;i++)
    {
        a[i]=999;
        scanf("%s",s);
        for(int j=0;j<26;j++)
            if(strlen(s)==strlen(modu[j].s)&&strcmp(s,modu[j].s)==0)
            {
                a[i]=modu[j].num;
                k++;
                break;
            }
    }
    std::sort(a,a+6,cmp);
    if(k==0)
        printf("0\n");
    else
    {
        int i=0;
        while(a[i]==0&&i<k-1) i++;
        printf("%d",a[i]);
        for(i++;i<k;i++) printf("%02d",a[i]);
    }
    return 0;
}
