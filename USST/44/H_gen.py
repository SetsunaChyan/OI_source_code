from cyaron import * 

for i in range(2, 11):
    test_data = IO(file_prefix="", data_id=i)
    
    n = 100

    tree = Graph.tree(n, 0.4, 0.35, weight_limit=100)
    
    test_data.input_writeln(n) 

    test_data.input_writeln(tree) 

for i in range(11, 21):
    test_data = IO(file_prefix="", data_id=i)
    
    n = 70000

    tree = Graph.tree(n, 0.4, 0.35, weight_limit=100000)
    
    test_data.input_writeln(n) 

    test_data.input_writeln(tree)