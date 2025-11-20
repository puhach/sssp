# Single-Source Shortest Path Problem

The Single-Source Shortest Path Problem (SSSP) is a fundamental problem in graph theory and computer science that aims to find the shortest paths from a single, designated starting vertex (source) to all other reachable vertices in a weighted graph.

The "length" or "weight" of a path is the sum of the weights of the edges along that path, and the goal is to minimize this sum.

SSSP is crucial for real-world tasks like network routing (e.g., finding the fastest route for a data packet), GPS navigation systems, and various logistics/transportation problems.

## Graph Representation

Common data structures used for representing graphs include adjacency lists, adjacency matrices, and edge lists.

### Adjacency List

An Adjacency List uses an array or hash map where each index (or key) represents a vertex, and the value is a list (or set) of its neighboring vertices.

* Advantages:
    * Space-efficient for sparse graphs - memory proportional to actual number of edges.
    * Efficient for iterating over all neighbors of a specific vertex.
    * Works well for algorithms that need to traverse the graph (BFS, DFS).
    * Easy to represent directed and weighted graphs: store pairs (neighbor, weight).

* Disadvantages:
    * Slower Edge Check: checking if an edge exists between two vertices $(u, v)$ can take $O(\text{deg}(u))$ time, where $\text{deg}(u)$ is the degree of vertex $u$.
    * Uses pointer-based structures, which may have overhead and cache inefficiency.
    * Harder to implement edge deletion efficiently unless using special data structures.

* Memory Complexity:
    * $O(V + E)$, where $V$ is the number of vertices and $E$ is the number of edges. Specifically, adjacency lists require storing each edge once (directed) or twice (undirected). This is usually the best space complexity.

### Adjacency Matrix

An Adjacency Matrix uses a $V \times V$ 2D array (or matrix) where $M[i][j]$ is $1$ (or the edge weight) if there is an edge from vertex $i$ to vertex $j$, and $0$ (or $\infty$) otherwise.

* Advantages:
    * Checking if an edge exists between any two vertices $(i, j)$ is $O(1)$.
    * Simple to implement and understand.
    
* Disadvantages:
    * Space Inefficient: For sparse graphs, much of the matrix will be empty (filled with zeros), leading to wasted space.
    * Slow Iteration: To find all neighbors of a vertex $i$, you must iterate through the entire $i$-th row, taking $O(V)$ time.
    
* Memory Complexity: 
    * $O(V^2)$, which can be prohibitive for graphs with many vertices.


### Edge List

Store the graph as a list of $(u, v)$ pairs (plus weight if needed).

* Advantages: 
    * Minimalistic and simple.
    * Very compact for sparse graphs.

* Disadvantages
    * Checking if an edge exists is $O(E)$.
    * Finding neighbors is also $O(E)$.
    * Identifying or processing vertices without edges can be more complex since the list only stores edges.

* Memory Complexity
    * $O(E)$, assuming you don't explicitly store the vertices, which you usually need to know, making it practically $O(V + E)$ in many implementations.


In this project the graph is represented by adjacency lists.

## Algorithms

The choice of an algorithm depends heavily on the nature of the graph, particularly the presence of negative edge weights or cycles. Here we explore the problem on a graph with integer non-negative weights. For unweighted graphs, my implementation of the Parallel Breadth-First Search algorithm is available [here](https://github.com/puhach/pbfs?tab=readme-ov-file#parallel-breadth-first-search).

### Bruteforce Approach

A basic shortest-path algorithm using brute-force search.

### Naive Dijkstra Algorithm

In the naive version, we simply scan all vertices linearly each time to find the minimum. That makes it $𝑂(𝑉)$ per selection, and since we do it $𝑉$ times, time complexity for processing all vertices is $𝑂(𝑉^2)$. Additionally, updating neighbor distances can occur up to 𝐸 times; hence the total time complexity is $𝑂(𝑉^2 + 𝐸)$.

### Dijkstra's Algorithm with Binary Heap

In heap-based Dijkstra's algorithm, we use a priority queue to quickly find the vertex with the smallest tentative distance and update the distance when we find a better path to a neighbor. Both operations take $𝑂(log𝑉)$ time in a binary heap. Each vertex is removed from the queue once and each edge can cause an update of the distance to the neighbor. Thus, the total time complexity is $𝑂((𝑉+𝐸)logV)$.

## Building

It is assumed that Git, CMake 3.14 or newer, and C++17 compiler are available on the system. Other dependencies will be automatically downloaded and built with the project.

Run the following commands:
```
git clone https://github.com/puhach/sssp
cd sssp
cmake -S . -B build
cmake --build build --config Release
```

## Testing

The implementation was validated using the test datasets provided at [stanford-algs](https://github.com/beaunus/stanford-algs/tree/master/testCases/course2/assignment2Dijkstra).

Execute `sssp` to run the tests. 

A separate program is developed for performance measurement and complexity analysis. It runs each shortest path algorithm on a randomly generated graph of various sizes and clocks the elapsed time. Then the tool estimates the complexity of the algorithms. Since Google Benchmark cannot reliably detect factorial complexity and we can only reasonably measure runtime of the brute-force implementation on a small graph (due to the explosive nature of the $O(N!)$ algorithm), a polynomial like $N^3$ can roughly fit the growth trend of N!.

To use the performance analysis tool run `sssp_benchmarks`.

It is recommended to run benchmarks in Release mode, which provides a closer approximation of the code's real-world performance, whereas Debug mode would give artificially slower results.

## Additional References

Check out [this](https://github.com/puhach/pbfs?tab=readme-ov-file#parallel-breadth-first-search) repository for my implementation of the Parallel Breadth-First Search algorithm that

