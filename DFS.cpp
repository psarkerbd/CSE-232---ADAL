#include<iostream>
#include<vector>

using namespace std;

const int white = 0, grey = 1, black = -1, high=100;

vector<int>adjacent[100]; // declaralation of 2D vector
int color[high], timee = 0, starting_time[high], finishing_time[high];

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

    // nodes are started from 0. the first node is 0

    for(int i=0; i<edge; i++)
    {
        cout << "Construct Edge " << i+1 << ": ";
        cin >> u >> v;

        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
        // beacause the graph is bidirectional or undirected
    }

    cout << "\nPrinting Adjacency Lists for each Node:\n";

    for(int i=0; i<node; i++) // as the first node is 0
    {
        cout << "The Adjacency List for node " << i << " -> ";

        for(int j=0; j<adjacent[i].size(); j++)
        {
            cout << adjacent[i][j] << " ";
        }

        cout << "\n";
    }
}

void initialization()
{
    for(int i=0; i<101; i++)
    {
        color[i] = white;
    }
}

void DFS_visit(int u)
{
    int v;
    color[u] = grey; // make color grey for the node, which is white
    // a node's color is grey means, it expanding the adjacents
    timee += 1; // count the timing

    starting_time[u] = timee; // stroing the starting time of node u
    
    for(int i=0; i<adjacent[u].size(); i++)
    {
        v = adjacent[u][i];
        if(color[v] == white)
        {
            DFS_visit(v);
        }
    }

    color[u] = black; // make color node black means it finishes the execution
    timee +=1;
    finishing_time[u] = timee; // stroing the finishing time of node u
    cout << u << " ";
}

void DFS(int node)
{
    initialization();

    for(int i=0; i<node; i++)
    {
        if(color[i] == white)
        {
            DFS_visit(i);
        }
    }

    cout << "\n\nStarting and Finishing time of nodes:\n";

    for(int i=0; i<node; i++)
    {
        cout << "Node " << i << ": " << "Starting time: " << starting_time[i] << " " << "Finishing time: " << finishing_time[i] << "\n";
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
    undirected_graph(node, edge);
    //directed_graph(node, edge);
    cout << "\nVisited nodes are : ";
    DFS(node);
    return 0;
}