from cyaron import * 

for i in range(2, 11):

    test_data = IO(file_prefix="", data_id=i)

    test_data.input_writeln(10)

    for j in range(1,10):
        
        n = 10000

        tree = Graph.tree(n, 0.4, 0.35)
        
        test_data.input_writeln(n,randint(1, n)) 

        test_data.input_writeln(tree.to_str(output=Edge.unweighted_edge)) 