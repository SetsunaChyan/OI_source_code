    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define ull unsigned long long
    #define sd(a) scanf("%d",&a)
    #define sld(a) scanf("%lld",&a)
    #define pr(a) printf("%d\n",a)
    #define per(a,b,c) for(int a=b;a<c;++a)
    #define perr(a,b,c) for(int a=b;a<=c;++a)
    #define rua() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define sl(a) scanf("%[^\n]",&a);getchar();
    #define ss(a) scanf("%s",a)
    const int inf=0x3f3f3f3f;

    int _;
    ll l[9],k,n;
    ll ans=0;
    int all=0;
    ll a[8][8];
    void gao(int x,int y,int pre,int count)
    {
        if(count==all+1)
        {
            ans++;
            return;
        }
        if(y==1)//每行第一个
        for(int i=a[x-1][1]+1;i<=n;++i)
        {
            if(k-x<=n-i)
            {
                a[x][y]=i;
                gao(y==l[x]?(x+1):x,y==l[x]?1:(y+1),i,count+1);
            }
        }
        else
        {
            int now=max(a[x][y-1],a[x-1][y]+1);
            for(int i=now;i<=n;++i)
            {
                a[x][y]=i;
                gao(y==l[x]?(x+1):x,y==l[x]?1:(y+1),i,count+1);
            }
        }
    }
    int main()
    {
        rua();
        while(cin>>k)
        {
            ans=0;all=0;
            //memset(a,0,sizeof(0));
            perr(i,1,k)
            {
                cin>>l[i];
                all+=l[i];
            }
            cin>>n;
            for(int i=1;i<=n;++i)
            {
                a[1][1]=i;
                gao(1==l[1]?2:1,1==l[1]?1:2,i,2);
            }
            cout<<ans<<endl;
        }

    }
