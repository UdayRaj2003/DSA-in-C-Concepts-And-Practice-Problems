#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjlist;

    void addEdge(int u, int v, int w, bool dir)
    {
        // dir->0 -> undirected
        // dir->1 -> directed

        if (dir)
        {
            adjlist[u].push_back({v, w});
        }
        else
        {
            adjlist[u].push_back({v, w});
            adjlist[v].push_back({u, w});
        }
    }
    void printadjlist()
    {
        for (auto i : adjlist)
        {
            cout << i.first << ": {";

            for (auto j : i.second)
            {
                cout << " {" << j.first << "," << j.second << "} ";
            }
            cout << "}" << endl;
        }
    }
    void topoOrderbyDfs(int src, stack<int> &topo, unordered_map<int, bool> &visited)
    {
        visited[src] = true;

        for (auto nbrPair : adjlist[src])
        {

            int nbrNode = nbrPair.first;
            if (!visited[nbrNode])
            {
                topoOrderbyDfs(nbrNode, topo, visited);
            }
        }
        topo.push(src);
    }
    void shortestPathbyDfs(int dest, vector<int> &dist, stack<int> &st)
    {
        while (!st.empty())
        {

            int src = st.top();
            st.pop();
            for (auto i : adjlist[src])
            {
                dist[i.first] = min(dist[i.first], dist[src] + i.second);
            }
        }
    }

    void dijkstraSD(int n, vector<int> &dist, set<pair<int, int>> &ar,int src,int dest)
    {
        while (!ar.empty())
        {
            pair<int, int> a = *ar.begin();
            ar.erase(ar.begin());

            for (auto i : adjlist[a.second])
            {
                if (dist[i.first] > dist[a.second] + i.second)
                {
                    auto it = ar.find({dist[i.first], i.first});
                    if (it != ar.end())
                        ar.erase(it);

                    dist[i.first] = min(dist[i.first], dist[a.second] + i.second);
                    ar.insert({dist[i.first], i.first});
                }
            }
        }
        cout<<"Distance of "<<src<<" to "<<dest<<" is "<<dist[dest]<<endl;
    }
};

void printv(vector<int> nums)
{
    for (auto i : nums)
    {
        cout << i;
        cout << " ";
    }
    cout << endl;
}

int main()
{
    graph g;
    // g.addEdge(0, 1, 5, 1);
    // g.addEdge(2, 4, 6, 1);
    // g.addEdge(0, 2, 3, 1);
    // g.addEdge(1, 3, 3, 1);
    // g.addEdge(2, 1, 2, 1);
    // g.addEdge(2, 3, 5, 1);
    // g.addEdge(4, 3, 1, 1);
    g.addEdge(1, 6, 14, 0);
    g.addEdge(1, 3, 9, 0);
    g.addEdge(1, 2, 7, 0);
    g.addEdge(2, 3, 10, 0);
    g.addEdge(2, 4, 15, 0);
    g.addEdge(3, 4, 11, 0);
    g.addEdge(6, 3, 2, 0);
    g.addEdge(6, 5, 9, 0);
    g.addEdge(5, 4, 6, 0);

    g.printadjlist();
    int src = 0;
    // stack<int> topo;
    // unordered_map<int, bool> vis;

    // g.topoOrderbyDfs(src, topo, vis);
    int n = g.adjlist.size();
    // vector<int> dist(n, INT_MAX);
    // dist[topo.top()] = 0;
    // int dest = 3;
    // g.shortestPathbyDfs(dest, dist, topo);
    // printv(dist);


    // Dijestra SD
    src =4;
    int dest =6;
    vector<int> dist(n+1, INT_MAX);
    dist[src] = 0;
    set<pair<int, int>> ar;
    ar.insert({0, src});
    g.dijkstraSD(n+1,dist,ar,src,dest);
    return 0;
}