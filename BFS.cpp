#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>adjacent[100]; // declaralation of 2D vector
int visited[150], par[150];

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

void initialization()
{
    for(int i=0; i<105; i++)
    {
        visited[i] = 0; // 0 means univisited, and 1 means visited
        par[i] = 0; // 0 indicates no parent for a node
    }
}

void printing_path(int source, int destination)
{
    if(source == destination)
    {
        cout << " " << source; 
    }

    else if(par[destination] == 0)
    {
        cout << "No Path here...";
    }

    else
    {
        printing_path(source, par[destination]);
        cout << " " << destination;
    }
}

void BFS(int start)
{
    initialization();
    queue<int>Q; // queue declaration in C++

    Q.push(start);
    visited[start] = 1;

    int u, v;

    while(!Q.empty())
    {
        u = Q.front(); //1
        
        Q.pop(); // remove the front element of queue

        cout << "\nThe visited Nodes are: ";

        cout << u << " ";

        for(int i=0; i<adjacent[u].size(); i++) // 1.size = 2
        {
            v = adjacent[u][i]; // adjacent[1][0] = 2, adjacent[1][1] = 3
            
            if(visited[v] == 0)
            {
                Q.push(v);
                visited[v] = 1;
                par[v] = u;
            }
        }
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
    cout << "\nEnter a starting node to run BFS: ";
    int start;
    cin >> start;
    cout << "\n\nRunning BFS...\n\n";
    BFS(start);

    int destination;

    //for(int i=1; i<=6; i++) cout << par[i] << " ";

    cout << "\n\nEnter your Destination node to see the path: ";

    cin >> destination;

    printing_path(start, destination);

    cout << "\n\nStop BFS...\n\n";
    return 0;
}