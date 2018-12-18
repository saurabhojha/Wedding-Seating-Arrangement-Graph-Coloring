# Wedding-Seating-Arrangement-Graph-Coloring
This project uses graph coloring to implement a wedding seating planner.

This code takes an adjacency matrix as input and max no of chairs and tables used in the wedding. It then gives an arrangement where all the guests who do not want to sit together are seated separately, thereby reducing chances of unwanted fights during the function :)

It uses the concept of graph coloring which is implemented using backtracking.
The adjacency matrix is as follows:
If in the matrix A , guest i does not want to sit with guest j (i,j) are distinct then Aij = Aji = 1.

Modelling the seating problem to graph coloring problem:
All the guests are considered to be nodes on the graph.
If two guests have issues sitting with each other, then there is an edge between those two nodes. 
Thus while assigning colors to the nodes, the connected nodes recieve different colors which in this case relates to guests with conflicts not getting the same table.

