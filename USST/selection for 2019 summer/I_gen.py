from cyaron import * 

for i in range(2, 21):

    test_data = IO(file_prefix="", data_id=i)
    
    n = 100000

    tree = Graph.tree(n, 0.4, 0.35, weight_limit=100000)
    
    test_data.input_writeln(n) 

    for j in range(0,n):

        test_data.input_write(randint(1, 1000000))

    test_data.input_writeln() 

    test_data.input_writeln(tree) 
