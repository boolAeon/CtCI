#include <iostream>
#include <list>

using namespace std;

class Graph {
        int num_V;
        list<int> *adj;
    public:
        Graph(int num_V);
        void addEdge(int u, int v);
        bool isReachable(int s, int d);
};

Graph::Graph(int num_V) {
    this->num_V = num_V;
    adj = new list<int> [num_V];   
 }

void Graph::addEdge(int u, int v)
{
     adj[u].push_back(v);
}

bool Graph::isReachable(int s, int d)
{
    if (s == d)
        return true;
    bool *visited = new bool [num_V] ();
    list<int> q;

    visited[s] = true;
    q.push_back(s);

    while (!q.empty()) {
        int ns = q.front();
        q.pop_front();        
        for (list<int>::iterator it = adj[ns].begin(); it != adj[ns].end(); ++it)
        {
            if (*it == d) {
                return true;    
            }    
            if (!visited[*it])
            {
                visited[*it] = true;
                q.push_back(*it);        
            }
        }
    }
    return false;
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    int u = 1, v = 3;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
 
    u = 3, v = 1;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
    cout << endl; 
    return 0;
}


