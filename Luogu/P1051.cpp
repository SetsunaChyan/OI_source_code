#include <cstdio>
#include <algorithm>

struct node
{
    int num,pj,py,lw,jxj;
    char name[21],gb,xb;
}s[100];

bool cmp(node a,node b)
{
    return a.jxj>b.jxj||a.jxj==b.jxj&&a.num<b.num;
}

int main()
{
    int sum=0,_;
    scanf("%d",&_);
    for(int i=0;i<_;i++)
    {
        scanf("%s%d%d%*c%c%*c%c%d",s[i].name,&s[i].pj,&s[i].py,&s[i].gb,&s[i].xb,&s[i].lw);
        s[i].jxj=0;
        s[i].num=i;
        if(s[i].lw&&s[i].pj>80) s[i].jxj+=8000;
        if(s[i].py>80&&s[i].pj>85) s[i].jxj+=4000;
        if(s[i].pj>90) s[i].jxj+=2000;
        if(s[i].xb=='Y'&&s[i].pj>85) s[i].jxj+=1000;
        if(s[i].gb=='Y'&&s[i].py>80) s[i].jxj+=850;
        sum+=s[i].jxj;
    }
    std::sort(s,s+_,cmp);
    printf("%s\n%d\n%d\n",s[0].name,s[0].jxj,sum);
    return 0;
}
