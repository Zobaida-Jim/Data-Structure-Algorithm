#include <iostream>
#include <list>
#include <vector>
using namespace std;

class graph
{
public:
    int v;
    list<int> *l;
    graph(int V)
    {
        v = V;
        l = new list<int>[v];
    }

    void addEdge(int u, int v) // u --- v
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void DFS(int u, vector<bool> &vis)
    {
        vis[u] = true;
        cout << u << " ";
        list<int> neighbours = l[u];
        for (int v : neighbours)
        {
            if (!vis[v])
            {
                DFS(v, vis);
            }
        }
    }
};

int main()
{
    graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(5, 6);

    vector<bool> vis(7, false);
    g.DFS(0, vis);
    cout << endl;
}