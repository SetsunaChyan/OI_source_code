from cyaron import * 

for i in range(2, 11):

    test_data = IO(file_prefix="", data_id=i)
    
    n = 50000 

    m = 200000

    test_data.input_writeln(n, m)

    graph = Graph.graph(n, m)
    
    test_data.input_writeln(graph.to_str(output=Edge.unweighted_edge))

    test_data.input_writeln(n)

    vec = Vector.random(n, [(1,n)])

    for j in range(0, n):

        test_data.input_writeln(vec[j])


for i in range(11, 21):

    test_data = IO(file_prefix="", data_id=i)
    
    n = 200000 

    m = 200000

    test_data.input_writeln(n, m)

    graph = Graph.graph(n, m)
    
    test_data.input_writeln(graph.to_str(output=Edge.unweighted_edge))

    test_data.input_writeln(n)

    vec = Vector.random(n, [(1,n)])

    for j in range(0, n):

        test_data.input_writeln(vec[j])