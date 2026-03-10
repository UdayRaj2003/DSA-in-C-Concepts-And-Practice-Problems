#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    unordered_map<int, list<int>> adjlist;
    void addedge(int u, int v, bool directed)
    {
        adjlist[u].push_back(v);
        if (!directed)
        {
            adjlist[v].push_back(u);
        }
    }
    void printgraph()
    {
        for (auto i : adjlist)
        {
            cout << i.first << ": ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    void toposortdfs(vector<bool> &vis, int src, stack<int> &st)
    {
        vis[src] = true;
        for (auto i : adjlist[src])
        {
            if (!vis[i])
                toposortdfs(vis, i, st);
        }

        st.push(src);
    }
    void toposortbybfs(vector<int> &st)
    {
        vector<int> indegree(8, 0);
        for (auto i : adjlist)
        {
            for (auto j : i.second)
            {
                indegree[j]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < 8; i++)
        {
            if (!indegree[i])
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int src = q.front();
            st.push_back(src);
            q.pop();
            for (auto i : adjlist[src])
            {
                indegree[i]--;
                if (!indegree[i])
                {
                    q.push(i);
                }
            }
        }
    }
    void shortestpathbybfs(int src)
    {
        queue<int> q;
        vector<int> dist(8, -1);
        q.push(src);
        dist[src] = 0;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (auto i : adjlist[front])
            {
                if (dist[i] == -1)
                {
                    dist[i] = dist[front] + 1;
                    q.push(i);
                }
            }
        }
        for (auto i : dist)
        {
            cout << i << " ";
        }
    }
    void shortestpathbydfs(int src, vector<int> &dist)
    {
        // dist[src]= dist[parent[src]]+1;
        for (auto i : adjlist[src])
        {
            if (dist[i] == -1)
            {
                dist[i] = dist[src] + 1;
                shortestpathbydfs(i, dist);
                // parent[i]=src;
            }
            else if (dist[i] > dist[src] + 1)
            {
                dist[i] = min(dist[i], dist[src] + 1);
                // parent[i]=src;
            }
        }
    }
};
int main()
{

    graph g;
    g.addedge(0, 1, 1);
    g.addedge(1, 2, 1);
    g.addedge(2, 3, 1);
    g.addedge(3, 4, 1);
    g.addedge(3, 5, 1);
    g.addedge(4, 6, 1);
    g.addedge(5, 6, 1);
    g.addedge(6, 7, 1);
    g.printgraph();
    vector<bool> vis(8, false); // 8 vertices: 0..7

    // stack<int> st;
    // g.toposortdfs(vis, 0, st);
    // cout << "Topo Sort by Dfs : ";
    //  while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }

    // vector<int> topo;
    // g.toposortbybfs(topo);

    // cout << "Topo Sort by Bfs : ";
    // for (auto i : topo)
    // {
    //     cout << i << " ";
    // }
    // g.shortestpathbybfs(0);
    vector<int> parent(8, -1);
    vector<int> dist(8, -1);
    dist[0] = 0;
    parent[0] = 0;
    g.shortestpathbydfs(0, dist);
    for (auto i : dist)
    {
        cout << i << " ";
    }
    return 0;
}