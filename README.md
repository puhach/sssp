# Single-Source Shortest Path Problem

## Bruteforce Implementation

A basic shortest-path algorithm using brute-force search.

## Naive Dijkstra Implementation

In the naive version, we simply scan all vertices linearly each time to find the minimum. That makes it 𝑂(𝑉) per selection, and since we do it 𝑉 times, time complexity for processing all vertices is 𝑂(𝑉<sup>2</sup>). Additionally, updating neighbor distances can occur up to 𝐸 times; hence the total time complexity is 𝑂(𝑉<sup>2</sup> + 𝐸).

## Dijkstra's Algorithm with Binary Heap

In heap-based Dijkstra's algorithm, we use a priority queue to quickly find the vertex with the smallest tentative distance and update the distance when we find a better path to a neighbor. Both operations take 𝑂(log𝑉) time in a binary heap. Each vertex is removed from the queue once and each edge can cause an update of the distance to the neighbor. Thus, the total time complexity is 𝑂((𝑉+𝐸)logV).
