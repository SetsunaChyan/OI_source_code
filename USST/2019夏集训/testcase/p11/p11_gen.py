from cyaron import *

for i in range(2,21):
    test_data=IO(file_prefix="",data_id=i)
    upper=100000
    q=30000
    if(i<=5):
        n=5
        m=5
        upper=100
        q=10
    elif(i<=10):
        n=10
        m=10
        upper=500
        q=10
    elif(i<=15):
        n=10000
        m=10000
    else:
        n=10000
        m=50000
    test_data.input_writeln(n,m)
    g=Graph.graph(n,m,repeated_edges=True,weight_limit=(5,upper),self_loop=False)
    test_data.input_writeln(g.to_str(shuffle=True))
    test_data.input_writeln(q)
    for j in range(0,q):
        x=0
        y=0
        while(x==y):
            x=randint(1,n)
            y=randint(1,n)
        test_data.input_writeln(x,y)
