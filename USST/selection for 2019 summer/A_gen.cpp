#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char des[100];
int fs[15];

int rnd(int l,int r)
{
    int k=((long long)rand())*rand()%(r-l+1);
    return l+k%(r-l+1);
}

void gen()
{
	int n=1000,m=15;
    printf("%d %d\n",n,m);
    char s[50];
    for(int peo=0;peo<n;peo++)
    {
        memset(fs,-1,sizeof(fs));
        for(int i=0;i<49;i++)
            s[i]='A'+rand()%26;
        s[49]=0;
        printf("%s\n",s);
        for(int i=0;i<m;i++)
        {
            int k=rand()%3;
            if(k==0)
            {
                printf("0 ");
            }
            else if(k==1)
            {
                printf("-%d ",1+rand()%100);
            }
            else 
            {
                int g=rand()%100;
                if(g==0) printf("+ ");
                else printf("+%d ",g);
                fs[i]=rand()%240;
            }
        }
        printf("\n");
        for(int i=0;i<m;i++)
            printf("%d ",fs[i]);
        printf("\n");
    }
    int h=1000;
    printf("%d\n",h);
    for(int i=0;i<h;i++)
        printf("%d %d %d %d\n",1+rand()%n,1+rand()%m,rand()&1,240+rand()%60);
}

int main()
{
    srand(time(NULL));
    for(int i=2;i<=20;i++)
    {
		sprintf(des,"%d.in",i);
	    freopen(des,"w",stdout);
	    gen();
	   	fclose(stdout); 	
	}
    return 0;
}
