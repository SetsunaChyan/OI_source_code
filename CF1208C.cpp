#include <bits/stdc++.h>
using namespace std;

int a[2005][2005],n;

void solve1()
{
    int i,j,k,x;
    if(n%4==0)
    {
        x=1;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                a[i][j]=x++;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(i%4==0&&abs(i-j)%4==0)
                    for(k=0; k<4; k++)
                        a[i+k][j+k]=n*n-a[i+k][j+k]+1;
                else if(i%4==3&&(i+j)%4==3)
                    for(k=0; k<4; k++)
                        a[i-k][j+k]=n*n-a[i-k][j+k]+1;
            }
    }
}

void solve2()
{
    int i,j,k,tot=0;
    for(i=0;i<n;i++)
        for(j=0; j<n; j++){
            a[i][j]=++tot;
        }
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(i%4==j%4||i%4+j%4==3)
                    a[i][j]=n*n+1-a[i][j];
                }
        }
}

bool check()
{
    int p=0,tmp;
    for(int i=0;i<n;i++) p^=a[0][i];
    for(int i=0;i<n;i++)
    {
        tmp=0;
        for(int j=0;j<n;j++) tmp^=a[i][j];
        printf("%d\n",tmp);
        if(tmp!=p) return false;
    }
    for(int i=0;i<n;i++)
    {
        tmp=0;
        for(int j=0;j<n;j++) tmp^=a[j][i];
        printf("%d\n",tmp);
        if(tmp!=p) return false;
    }
    return true;
}

void solve3()
{
    int qaq=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=qaq++;
    //for(int i=0;i<n;i+=2)
    //    reverse(a[i],a[i]+n);
    for(int i=0; i<n/2; i++)
        swap(a[n-i+1][i],a[i][n-i-1]);
    for(int i=0; i<n/2; i++)
        swap(a[i][i],a[n-i+1][n-i+1]);
}

void solve4()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[0][i]=;
    for(int i=1;i<n;i++)
        for(int j=0;j<n;j++)

}

int main()
{
    scanf("%d",&n);
    solve3();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",a[i][j]=a[i][j]);
        printf("\n");
    }
    printf("check %d\n",check());
    return 0;
}
