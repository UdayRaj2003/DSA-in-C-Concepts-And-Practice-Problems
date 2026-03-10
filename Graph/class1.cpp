#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    // Adjacency list: node -> list of {neighbor, weight}
    unordered_map<int, list<pair<int, int>>> adjList;

    // Add an edge: for directed graphs set directed=true
    void addEdge(int u, int v, bool directed, int weight)
    {
        adjList[u].push_back({v, weight});
        if (!directed)
        {
            adjList[v].push_back({u, weight});
        }
    }

    // Utility function to print the list of neighbors for a node
    void printList(const list<pair<int, int>> &neighbors)
    {
        cout << "{";
        for (const auto &nbr : neighbors)
        {
            cout << " " << nbr.first << "(" << nbr.second << ")";
        }
        cout << " }";
    }

    // Print the whole graph's adjacency list
    void printGraph()
    {
        for (const auto &node : adjList)
        {
            cout << node.first << " -> ";
            printList(node.second);
            cout << endl;
        }
    }

    // ---------------- Topological Sort (DFS-based) ----------------

    // Recursive DFS for topological sorting
    void toposortdfs(unordered_map<int, bool> &vis, int src, stack<int> &s)
    {
        vis[src] = true;
        for (const auto &edge : adjList[src])
        {
            int nbr = edge.first;
            if (!vis[nbr])
            {
                toposortdfs(vis, nbr, s);
            }
        }
        s.push(src);
    }

    // Perform topological sort; valid only for DAGs.
    void performTopologicalSort()
    {
        unordered_map<int, bool> vis;
        stack<int> s;
        // Ensure all nodes are processed (for disconnected graphs)
        for (const auto &node : adjList)
        {
            if (!vis[node.first])
            {
                toposortdfs(vis, node.first, s);
            }
        }

        cout << "\nTopological Sort (Valid for DAG): ";
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    // ---------------- Cycle Detection in Directed Graph ----------------

    // DFS-based cycle detection: returns true if a cycle is detected.
    bool detectCycleDFS(int node, unordered_map<int, bool> &vis, unordered_map<int, bool> &recStack)
    {
        vis[node] = true;
        recStack[node] = true;

        for (const auto &edge : adjList[node])
        {
            int nbr = edge.first;
            if (!vis[nbr])
            {
                if (detectCycleDFS(nbr, vis, recStack))
                    return true;
            }
            else if (recStack[nbr])
            {
                // Neighbor is in the current recursion stack: cycle found.
                return true;
            }
        }

        recStack[node] = false; // Backtrack
        return false;
    }

    // Check if the graph has a cycle.
    bool hasCycle()
    {
        unordered_map<int, bool> vis;
        unordered_map<int, bool> recStack;
        // Process all nodes (in case the graph is disconnected)
        for (const auto &node : adjList)
        {
            if (!vis[node.first])
            {
                if (detectCycleDFS(node.first, vis, recStack))
                    return true;
            }
        }
        return false;
    }

    void toposortbybfs(int src, int node)
    {
        // unordered_map<int, list<pair<int, int>>> adjList;
        unordered_map<int, int> indegree;
        queue<int> q;
        for (auto i : adjList)
        {
            for (auto j : i.second)
            {
                indegree[j.first]++;
            }
        }
        for (int i = 0; i < node; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        // bfsssss
        while (!q.empty())      
        {   
            int frontnode = q.front();
            q.pop();
            cout<<frontnode<<" ";
            for(auto i : adjList[frontnode]){
                indegree[i.first]--;

                if(indegree[i.first]==0){
                    q.push(i.first);
                }

                
            }
        }
        
    }
};

int main()
{
    Graph g;

    // Creating a sample directed graph.
    // This graph is initially acyclic.
    g.addEdge(0, 1, true, 1);
    g.addEdge(1, 2, true, 1);
    g.addEdge(2, 3, true, 1);
    // Uncomment the following line to introduce a cycle (3 -> 1):
    // g.addEdge(3, 1, true, 1);

    cout << "Graph Representation (Adjacency List):\n";
    g.printGraph();

    // Check for cycles first.
    if (g.hasCycle())
    {
        cout << "\nCycle Detected: Topological sort not possible.\n";
    }
    else
    {
        // g.performTopologicalSort();
        g.toposortbybfs(0,4);
    }

    return 0;
}
