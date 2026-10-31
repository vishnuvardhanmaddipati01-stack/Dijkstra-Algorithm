# Dijkstra's Shortest Path in C

Find shortest distances and paths from a source vertex in a weighted graph with non-negative edge weights.

## Compile and run
```bash
gcc src/dijkstra.c -o dijkstra
./dijkstra
```
On Windows, run `dijkstra.exe` after compiling.

## Input
Enter the number of vertices, an adjacency matrix, then a source vertex. Vertices are numbered `0` through `n-1`. In this implementation, `0` means no edge, so edge weights must be positive; the diagonal should be zero.

## Complexity
- Time: `O(V^2)` using an adjacency matrix.
- Space: `O(V^2)` for the matrix.

## Limitation
This version supports non-negative weights and does not represent zero-weight edges.
