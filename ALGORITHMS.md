Algorithms Used

This project uses two algorithms to find the shortest path in a graph:
Dijkstra’s Algorithm and Bellman–Ford Algorithm.
Both find the shortest distance from a given starting vertex to all other vertices in a weighted graph.

🔹 Dijkstra’s Algorithm
Dijkstra’s algorithm finds the shortest path from a source vertex to all other vertices, but it only works correctly when all edge weights are positive.
steps:
Start with all vertices marked as unvisited.
Set the distance of the source vertex to 0, and all others to infinity (a very large number).
Pick the vertex with the smallest distance that hasn’t been visited yet.
From this vertex, check all its neighboring vertices and update their distances if a shorter path is found.
For example, if the distance to A is 4 and the edge from A to B has weight 2,
then the new distance to B = 4 + 2 = 6.
Once you have checked all neighbors, mark the current vertex as visited.
Repeat steps 3–5 until all vertices are visited or the destination is reached.
The final distances give the shortest path from the source to all other vertices.

Key Points
Works only for positive weights.
Uses a greedy method (chooses the nearest vertex each time).
Faster than Bellman–Ford for small graphs.

🔹 Bellman–Ford Algorithm
The Bellman–Ford algorithm also finds the shortest path from a source vertex to all others.
Unlike Dijkstra, it works even when some edges have negative weights and can also detect negative weight cycles.

Steps
Set the distance of the source vertex to 0, and all other vertices to infinity.
Repeat the following steps V−1 times (where V is the number of vertices):
Go through each edge (u, v) in the graph.
If the distance to u plus the edge weight (u → v) is less than the current distance to v,
update the distance to v.
Example: if distance to u is 5 and edge weight is −2,
new distance to v = 5 + (−2) = 3.
After repeating this process, all shortest paths will be found.
Finally, go through all edges one more time.
If any distance can still be reduced, it means there is a negative weight cycle in the graph.

Key Points
Works for both positive and negative weights.
Can detect negative cycles.
Slower than Dijkstra because it checks all edges multiple times.

Summary
Use Dijkstra’s algorithm when all edge weights are positive.

Use Bellman–Ford algorithm when the graph may contain negative edges.

Bellman–Ford is more powerful, but Dijkstra is faster for simple graphs.
