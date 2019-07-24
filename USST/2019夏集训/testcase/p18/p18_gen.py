from cyaron import *

for i in range(2, 21):
    test_data=IO(file_prefix="",data_id=i)
    upper=10000
    if(i<=5):
        n=5
        m=10
        upper=10
    elif(i<=10):
        n=10
        m=3*i
        upper=50
    elif(i<=15):
        n=1000
        m=10000
    else:
        n=50000
        m=100000
    test_data.input_writeln(n,m)
    test_data.input_writeln(randint(1,100),randint(1,2+int(upper/100)),randint(1,2+int(n/100)))
    g=Graph.UDAG(n,m,repeated_edges=False,weight_limit=(5,upper),self_loop=False)
    test_data.input_writeln(g.to_str(shuffle=True))
