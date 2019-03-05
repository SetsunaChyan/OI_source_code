#include <cstdio>

int pa1=0,pa2=0,pb1=0,pb2=0,a,b,t1,t2,t3;

int main()
{
    scanf("%d%d%d%d%d",&pa1,&pb1,&t1,&t2,&t3);
    if(t1) pb2+=1; else pa2+=1;
    if(t2) pb2+=1; else pa2+=1;
    if(t3) pb2+=1; else pa2+=1;
    if(pa1>pb1&&pa2)
        printf("The winner is a: %d + %d",pa1,pa2);
    else
        printf("The winner is b: %d + %d",pb1,pb2);
    return 0;
}