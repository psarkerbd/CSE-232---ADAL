#include<iostream>
using namespace std;

const int s_ze = 100;

int parent[s_ze];

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

void unionn(int a, int b)
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

int main()
{
    int numNodes, numRelation, a, b;
    cout << "Enter Number of Nodes and Number of Relations: ";
    cin >> numNodes >> numRelation;
    make_set(numNodes);
    int rel = 0;
    cout << "Enter the Nodes:\n";
    while(numRelation--)
    {
        cout << "Relation " << rel+1 << ": ";
        cin >> a >> b;
        unionn(a, b);
        rel++;
    }
    int component = 0;
    for(int i=1; i<=numNodes; i++)
    {
        cout << i << "\n";
        if(findd(i) == i)
        {
            component++;
        }
    }
    cout << "\nTotal Subgraph = " << component << "\n";
    return 0;
}