#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// =================== Task Scheduling (Priority Queue) ===================
class Task {
public:
    int id, priority;
    Task(int id, int priority) : id(id), priority(priority) {}
    bool operator<(const Task& other) const {
        return this->priority < other.priority;  // Higher priority has higher number
    }
};

class TaskScheduler {
    priority_queue<Task> taskQueue;

public:
    void addTask(int id, int priority) {
        taskQueue.push(Task(id, priority));
    }

    void processTasks() {
        while (!taskQueue.empty()) {
            Task current = taskQueue.top();
            cout << "Processing task ID: " << current.id << " with priority: " << current.priority << endl;
            taskQueue.pop();
        }
    }
};

// =================== Resource Allocation (Greedy) ===================
struct Resource {
    int id, value, weight;
};

bool compare(Resource a, Resource b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;  // Value per unit weight
}

class ResourceAllocator {
public:
    void allocateResources(vector<Resource>& resources, int maxCapacity) {
        sort(resources.begin(), resources.end(), compare);

        int totalValue = 0, totalWeight = 0;
        for (auto& resource : resources) {
            if (totalWeight + resource.weight <= maxCapacity) {
                totalValue += resource.value;
                totalWeight += resource.weight;
                cout << "Allocated resource ID: " << resource.id << " Total Value: " << totalValue << endl;
            }
        }
        cout << "Maximized value within capacity: " << totalValue << endl;
    }
};

// =================== Pathfinding (Dijkstra's Algorithm) ===================
#define INF INT_MAX
class Graph {
    int V;
    vector<vector<pair<int, int>>> adjList; // (neighbor, weight)

public:
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight}); // For undirected graph
    }

    void dijkstra(int source) {
        vector<int> dist(V, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Output distances from source to all other vertices
        for (int i = 0; i < V; i++) {
            if (dist[i] == INF) {
                cout << "Vertex " << i << ": INF" << endl;
            } else {
                cout << "Distance from source to vertex " << i << ": " << dist[i] << endl;
            }
        }
    }
};

// =================== N-Queens Solver (Backtracking) ===================
class NQueensSolver {
    int N;
    vector<vector<int>> board;

public:
    NQueensSolver(int N) : N(N), board(N, vector<int>(N, 0)) {}

    bool isSafe(int row, int col) {
        // Check row on left side
        for (int i = 0; i < col; i++)
            if (board[row][i])
                return false;
        // Check upper diagonal on left side
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j])
                return false;
        // Check lower diagonal on left side
        for (int i = row, j = col; j >= 0 && i < N; i++, j--)
            if (board[i][j])
                return false;
        return true;
    }

    bool solveNQueens(int col) {
        if (col >= N)
            return true;

        for (int i = 0; i < N; i++) {
            if (isSafe(i, col)) {
                board[i][col] = 1;
                if (solveNQueens(col + 1))
                    return true;
                board[i][col] = 0; // Backtrack
            }
        }
        return false;
    }

    void printBoard() {
        for (auto& row : board) {
            for (auto cell : row)
                cout << cell << " ";
            cout << endl;
        }
    }
};

// =================== Main function to run test cases ===================
int main() {
    // Test Case 1: Task Scheduling
    cout << "== Task Scheduling ==" << endl;
    TaskScheduler scheduler;
    scheduler.addTask(1, 5);
    scheduler.addTask(2, 3);
    scheduler.addTask(3, 9);
    scheduler.processTasks();
    cout << endl;

    // Test Case 2: Resource Allocation
    cout << "== Resource Allocation ==" << endl;
    vector<Resource> resources = {{1, 60, 10}, {2, 100, 20}, {3, 120, 30}};
    ResourceAllocator allocator;
    allocator.allocateResources(resources, 50);
    cout << endl;

    // Test Case 3: Pathfinding (Dijkstra's Algorithm)
    cout << "== Pathfinding (Dijkstra's Algorithm) ==" << endl;
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);
    g.addEdge(1, 4, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(4, 2, 9);
    g.addEdge(4, 3, 2);
    g.addEdge(2, 3, 6);
    g.dijkstra(0);
    cout << endl;

    // Test Case 4: N-Queens Problem
    cout << "== N-Queens Solver ==" << endl;
    NQueensSolver solver(8);
    if (solver.solveNQueens(0)) {
        solver.printBoard();
    } else {
        cout << "No solution found" << endl;
    }
    cout << endl;

    return 0;
}
