#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int s_ze = 100;
int parent[s_ze];

struct node
{
    int u, v, w;
    node(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator < (const node &p) const // operator overloading for the ascending order sort of edges
    {
        return w < p.w;
    }
};

vector<node>edges; // vector is a Queue data structure and it is easy to sort (ascending order)

void make_set(int numNodes)
{
    for(int i=1; i<=numNodes; i++)
    {
        parent[i] = i;
    }
}

int findd(int r)
{
    if(parent[r] == r)
    {
        return r;
    }
    else
    {
        return parent[r] = findd(parent[r]); // path compression
    }
}

/*void unionn(int a, int b)
{
    int u = findd(a); // finding the parent of a
    int v = findd(b); // finding the parent of b
    if(u == v)
    {
        //cout << "They are friends already\n";
        return;
    }
    else
    {
        //parent[v] = u;
        parent[u] = v; // create parent-child relation between them
    }
}
*/

void Kruskal(int numNodes)
{
    sort(edges.begin(), edges.end()); // sorted the edges based on their weight
    int sum = 0, numEdge=0, selectedEdge=0;
    for(int i=0; i<edges.size(); i++)
    {
        int u = findd(edges[i].u); // finding the parent of u
        int v = findd(edges[i].v); // finding the parent of v
        if(u != v)
        {
            cout << "Selected Edge " << selectedEdge + 1 << ": ";
            cout << edges[i].u << " " << edges[i].v << "\n";
            selectedEdge++;
            parent[u] = v;
            sum += edges[i].w; // adding the minimum weight of nodes
            numEdge+=1;
            if(numEdge == numNodes - 1)
            {
                break;
            }
        }
    }

    cout << "\nThe Weight of the MST is: " << sum << "\n";
}

int main()
{
    int numNodes, numEdges, a, b, w;
    cout << "Enter Number of Nodes and Number of Edges: ";
    cin >> numNodes >> numEdges;
    make_set(numNodes);
    cout << "\nEnter Edges and their Weight:\n";
    for(int i=1; i<=numEdges; i++)
    {
        cout << "Edge " << i << ": ";
        cin >> a >> b >> w;
        edges.push_back(node(a, b, w)); // 2 nodes and their weight are inserted into vector
    }
    Kruskal(numNodes);
    return 0;
}
