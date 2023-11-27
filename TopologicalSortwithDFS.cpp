#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int white = 0, grey = 1, black = -1;
vector<int>adjacencyList[100];
vector<int>topo_order;
void DFS(int color[], int u)
{
    color[u] = grey; // made the current node is grey
    for(int i=0; i<adjacencyList[u].size(); i++)
    {
        int v = adjacencyList[u][i]; // taking the adjacent node
        if(color[v] == white)
        {
            DFS(color, v);
        }
    }
    color[u] = black; // finished traversing the node and made it as black
    topo_order.push_back(u); // stroing the task but it is not in order
}
void TopologicalSort(int numTasks)
{
    int color[numTasks + 1];
    for(int i=1; i<=numTasks; i++) // initializing the tasks/nodes as white
    {
        color[i] = white;
    }
    for(int i=1; i<=numTasks; i++)
    {
        if(color[i] == white)
        {
            DFS(color, i);
        }
    }
    
    reverse(topo_order.begin(), topo_order.end()); // reverse the dfs list and make the topo order

    cout << "\nThe Order of Tasks is:\n";
    cout << topo_order[0];
    for(int i=1; i<topo_order.size(); i++)
    {
        cout << " -> " << topo_order[i];
    }
}
int main()
{
    int numTasks, relations;
    cout << "Enter number of Tasks and number of their Relations: ";
    cin >> numTasks >> relations;
    for(int i=0; i<relations; i++)
    {
        cout << "\nEnter Relation " << i+1 << ": ";
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v); // creating the adjacency list
    }
    TopologicalSort(numTasks);
    return 0;
}