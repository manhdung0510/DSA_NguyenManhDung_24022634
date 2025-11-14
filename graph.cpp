#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Graph {
    int V;                         
    vector<vector<int>> adj;       

    Graph(int V) {
        this->V = V;
        adj.resize(V);            
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);       
        adj[v].push_back(u);       
    }

    
    void DFS_helper(int v, bool visited[]) {
        visited[v] = true;         
        cout << v << " ";          

        for (int i = 0; i < adj[v].size(); i++) {
            int neighbor = adj[v][i];
            if (!visited[neighbor]) {
                DFS_helper(neighbor, visited);  
            }
        }
    }

   
    void DFS(int startNode) {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        DFS_helper(startNode, visited);

        delete[] visited;
    }

    
    void BFS(int startNode) {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        list<int> queue;

        visited[startNode] = true;
        queue.push_back(startNode);

        while (!queue.empty()) {
            int v = queue.front();
            queue.pop_front();

            cout << v << " ";

            for (int i = 0; i < adj[v].size(); i++) {
                int neighbor = adj[v][i];
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push_back(neighbor);
                }
            }
        }

        delete[] visited;
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    cout << "DFS: ";
    g.DFS(0);

    cout << endl;

    cout << "BFS: ";
    g.BFS(0);

    return 0;
}

