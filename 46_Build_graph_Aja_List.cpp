#include <iostream>
#include <list>
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

    void print()
    {
        for (int u = 0; u < v; u++) // 0, 1, 2, 3, 4
        {
            list<int> neighbours = l[u];
            cout << u << " : ";
            for (int v : neighbours)
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph g(5); // number of vertices
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.print();

    return 0;
}