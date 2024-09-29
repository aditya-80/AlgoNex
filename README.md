The AlgoNex project has four main components, each focusing on solving real-world problems using different data structures and algorithms.

1. Task Scheduling:
  Priority Queue: This keeps the highest-priority task at the top. If you add tasks with different priorities, the task with the highest number (priority) gets processed first.
  Method: Tasks are added to the queue, and when processTasks() is called, tasks are taken out one by one based on their priority.

2. Resource Allocation:
  Greedy Approach: We calculate the value-to-weight ratio for each resource, which tells us how valuable it is per unit of weight. Then, we sort the resources by this ratio and keep adding the most valuable ones to our "bag" until it's full.
  Method: The resources are sorted, and we keep adding them to maximize the total value without exceeding the capacity.

3. Pathfinding (Dijkstra’s Algorithm):
  Graph Representation: The graph is represented as a list of vertices where each vertex has a list of its neighbors (connected vertices) and the distance (weight) to them.
  Dijkstra’s Logic: Starting from the source, we visit each neighboring vertex and update the shortest distance to it. We keep track of the shortest path to each vertex and stop when all have been visited.

4. N-Queens (Backtracking):
  Placing Queens: We try placing a queen in the first column, then move to the next column. Each time we place a queen, we check if it’s safe (no other queens can attack it). If it’s not safe, we backtrack and try a different row.
  Method: The algorithm explores different positions recursively, backing up when it hits a problem, until it finds a solution.
