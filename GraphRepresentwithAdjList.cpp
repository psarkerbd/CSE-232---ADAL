#include<iostream>
#include<vector>

using namespace std;

vector<int>adjacent[100]; // declaralation of 2D vector

void directed_graph(int node, int edge)
{
    int u, v;

    for(int i=0; i<edge; i++)
    {
        cout << "Construct Edge " << i+1 << ": ";
        cin >> u >> v;

        adjacent[u].push_back(v);
        //adjacent[v].push_back(u);
        // beacause the graph is unidirectional or directed
    }

    cout << "\nPrinting Adjacency Lists for each Node:\n";

    for(int i=1; i<=node; i++)
    {
        cout << "The Adjacency List for node " << i << " -> ";

        for(int j=0; j<adjacent[i].size(); j++)
        {
            cout << adjacent[i][j] << " ";
        }

        cout << "\n";
    }
}

void undirected_graph(int node, int edge)
{
    int u, v;

    for(int i=0; i<edge; i++)
    {
        cout << "Construct Edge " << i+1 << ": ";
        cin >> u >> v;

        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
        // beacause the graph is bidirectional or undirected
    }

    cout << "\nPrinting Adjacency Lists for each Node:\n";

    for(int i=1; i<=node; i++)
    {
        cout << "The Adjacency List for node " << i << " -> ";

        for(int j=0; j<adjacent[i].size(); j++)
        {
            cout << adjacent[i][j] << " ";
        }

        cout << "\n";
    }
}

int main()
{
    int node, edge;
    cout << "Enter number of Nodes: ";
    cin >> node;
    cout << "Enter number of Edges: ";
    cin >> edge;
    cout << "\nCreate your graph:\n";
    //undirected_graph(node, edge);
    directed_graph(node, edge);
    return 0;
}