/*
INTUITION:
This problem is about finding the Minimum Spanning Tree (MST) using Prim’s Algorithm.
The idea is to always pick the edge with the minimum weight that connects a new node
to the growing MST. We use a priority queue to greedily select the smallest edge.
If a node is already visited, we skip it to avoid cycles. This ensures we connect all
nodes with minimum total cost.
*/
class cmp
{
public:
    bool operator()(const pair<int, pair<int, int>> &a,
                    const pair<int, pair<int, int>> &b)
    {
        if (a.first == b.first)
        {
            return a.second.first > b.second.first;
        }
        return a.first > b.first;
    }
};
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &ed)
    {
        vector<int> vis(V, 0);
        vector<vector<pair<int, int>>> g(V);
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       cmp>
            pq;
        pq.push({0, {0, -1}});
        int sum = 0;

        for (auto e : ed)
        {
            int u = e[0], v = e[1], w = e[2];
            g[v].push_back({u, w});
            g[u].push_back({v, w});
        }

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int node = top.second.first;
            if (vis[node])
            {
                continue;
            }
            sum += top.first;
            vis[node] = 1;
            for (auto i : g[node])
            {
                if (!vis[i.first])
                {
                    pq.push({i.second, {i.first, node}});
                }
            }
        }
        return sum;
    }
};