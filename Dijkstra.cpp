#include<iostream>
#include<queue>
using namespace std;

const int inf = INT_MAX, s_ze = 1000;
vector<int>adjacents[s_ze], weight[s_ze];

struct node // declaring a structure containing a node and its weight/cost
{
    int u, cost;
    node(int _u, int _cost)
    {
        u = _u; // assigining _u (given node) in the main node u
        cost = _cost; // assigining _cost or weight in the main cost
    }

    bool operator < (const node &p) const // Operator overloading
    {
        return cost > p.cost;
    }
};

void Dijkstra(int source, int nodes)
{
    int distance[nodes+1], u, v;

    for(int i=1; i<=nodes; i++)
    {
        distance[i] = inf; // assigning INFINITY to all nodes
    }

    priority_queue<node>Q; // declared a priority queue integrated with a structure
    Q.push(node(source, 0)); // inserted source node and its cost to the Q
    
    distance[source] = 0; // making the cost of source node is 0 according to the algorithm

    while(!Q.empty())
    {
        u = Q.top().u;
        Q.pop(); // poping/deleting the Q's first node or vertex

        for(int i=0; i<adjacents[u].size(); i++)
        {
            v = adjacents[u][i]; // adjacents of u

            // node or vertex relaxation
            if(distance[u] + weight[u][i] < distance[v])
            {
                distance[v] = distance[u] + weight[u][i]; // stroing the minimum cost for each node
                Q.push(node(v, distance[v]));
            }
        }
    }

    cout << "\n\nPrinting the Minimum Cost for each node:\n\n";
    for(int i=1; i<=nodes; i++)
    {
        cout << "From node " << source << " to " << i << " cost is --> " << distance[i] << "\n";
    }
}

int main()
{
    int numNodes, numEdges, u, v, w;
    cout << "Enter Number of Nodes and Number of Edges: ";
    cin >> numNodes >> numEdges;
    cout << "\nCreating Adjacency Lists with Weights:\n";
    cout << "Enter Node 1 Node 2 and their Weight:\n";
    for(int i=0; i<numEdges; i++)
    {
        cout << "Construct Edge " << i+1 << ": ";
        cin >> u >> v >> w;
        adjacents[u].push_back(v);
        adjacents[v].push_back(u);
        weight[u].push_back(w);
        weight[v].push_back(w);
    }

    cout << "\nPrinting Adjaceny Lists:\n";
    for(int i=1; i<=numNodes; i++)
    {
        cout << "Node " << i << " adjacents are : ";
        for(int j=0; j<adjacents[i].size(); j++)
        {
            cout << adjacents[i][j] << " (" << weight[i][j] << ") ";
        }
        cout << "\n";
    }

    cout << "\n\nStarting Dijkstra to find the Shortest Path for each node:\n";
    int source_node;
    cout << "\nEnter the Source Node: ";
    cin >> source_node;
    Dijkstra(source_node, numNodes);
    return 0;
}