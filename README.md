DSA Mini-Project – Finding the Shortest Path in a Graph using Dijkstra and Bellman–Ford algorithms in C Language

Topic: Finding Shortest Path in a Graph
Language: C
IDE Used: Code::Blocks

📄 Description

This mini-project implements Dijkstra and Bellman–Ford algorithms in C to find the shortest path between two vertices in a weighted graph and compare their results.

Dijkstra works only for graphs with non-negative weights.

Bellman–Ford works for graphs with negative weights and can detect negative cycles.

⚙️ How to Run

Open main.c in Code::Blocks.

Compile and run the program.

Enter:

Number of vertices and edges

Edge details in the format (u v w)

Source and destination vertices

📝 Example Input
Enter number of vertices and edges: 4 5
Enter edges (u v w):
0 1 2
1 2 3
1 3 5
2 3 1
0 2 6
Enter source vertex: 0
Enter destination vertex: 3

✅ Example Output
Dijkstra's Algorithm
Vertex  Distance  Path (with weights)
0       0         0

1       2         0(2) -> 1

2       5         0(2) -> 1(3) -> 2

3       6         0(2) -> 1(3) -> 2(1) -> 3

Bellman–Ford Algorithm
Vertex  Distance  Path (with weights)
0       0         0

1       2         0(2) -> 1

2       5         0(2) -> 1(3) -> 2

3       6         0(2) -> 1(3) -> 2(1) -> 3

Final Result
Source: 0   Destination: 3  
Shortest Distance = 6  
Path: 0(2) -> 1(3) -> 2(1) -> 3
(Result verified by both algorithms)

📌 Notes

Both Dijkstra and Bellman–Ford give the same result for graphs with positive weights.

For graphs containing negative edge weights, only Bellman–Ford gives correct results.
