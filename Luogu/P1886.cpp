#include <cstdio>

struct queue
{
    int head,end,num[1000000],pos[1000000];
    queue()
    {
        head=0;
        end=0;
    }
    int back()
    {
        return num[end-1];
    }
    void pop_back()
    {
        end--;
    }
    int front()
    {
        return num[head];
    }
    int front_p()
    {
        return pos[head];
    }
    void pop()
    {
        head++;
    }
    void push(int x,int p)
    {
        pos[end]=p;
        num[end++]=x;
    }
    bool empty()
    {
        return head==end;
    }
}q1,q2;

int n,k,a[1000000],ans1[1000000],ans2[1000000];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<k;i++)
    {
        while(!q1.empty()&&a[i]>q1.back()) q1.pop_back();
        q1.push(a[i],i);
        while(!q2.empty()&&a[i]<q2.back()) q2.pop_back();
        q2.push(a[i],i);
    }
    ans1[0]=q1.front();
    ans2[0]=q2.front();
    for(int i=k;i<n;i++)
    {
        while(!q1.empty()&&a[i]>q1.back()) q1.pop_back();
        q1.push(a[i],i);
        if(q1.front_p()<i-k+1) q1.pop();
        while(!q2.empty()&&a[i]<q2.back()) q2.pop_back();
        q2.push(a[i],i);
        if(q2.front_p()<i-k+1) q2.pop();
        ans1[i-k+1]=q1.front();
        ans2[i-k+1]=q2.front();
    }
    for(int i=0;i<=n-k;i++)
    {
        printf("%d ",ans2[i]);
    }
    printf("\n");
    for(int i=0;i<=n-k;i++)
    {
        printf("%d ",ans1[i]);
    }

    return 0;
}
