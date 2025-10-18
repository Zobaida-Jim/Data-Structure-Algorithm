#include <iostream>
#include <queue>
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

    void addEdge(int u, int v) // u ---- v
    {
        l[v].push_back(u);
        l[u].push_back(v);
    }

    void BFS()
    {
        queue<int> q;
        vector<bool> vis(v, false);

        q.push(0);
        vis[0] = true;

        while (q.size() > 0)
        {
            int u = q.front(); // current vertex
            q.pop();
            cout << u << " ";

            list<int> neighbours = l[u];
            for (int v : neighbours)
            {
                if (vis[v] != true)
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
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

    g.BFS();

    return 0;
}