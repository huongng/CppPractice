#include <iostream>
#include <vector>
#include <queue>

class Graph
{
private:
    int V;
    std::vector< std::vector<int> > adjacencies;
    void printAllPathsUtils(int v, int e, bool visited[], std::vector<int>& paths);
public:
    Graph(int V) : V(V)
    {
        adjacencies = std::vector< std::vector<int> >(V);
    }
    void addEdge(int src, int dst);
    void printAllPaths(int v, int e);
    bool allVisited(int v, bool visited[]);
    void printGraph();
};

void Graph::addEdge(int src, int dst)
{
    adjacencies[src].push_back(dst);
    adjacencies[dst].push_back(src);
}

void print_paths(std::vector<int>& paths)
{
    for (auto p = paths.begin(); p != paths.end(); p++) {
        std::cout << *p << " ";
    }
    std::cout << std::endl;
}
bool Graph::allVisited(int v, bool visited[])
{
    bool all = true;
    for (auto p = adjacencies[v].begin(); p != adjacencies[v].end(); p++) {
        if (!visited[*p]) all = false;
    }
    return all;
}
void Graph::printAllPathsUtils(int v, int e, bool visited[], std::vector<int>& paths)
{
    visited[v] = true;
    //std::cout << v << std::endl;
    paths.push_back(v);

    // if (v == e) {
    //     std::cout << "found paths: ";
    //     print_paths(paths);
    //     //return;
    // }
    if (allVisited(v, visited)) {
        std::cout << "found a path: ";
        print_paths(paths);
    }
    else {
    for (auto p = adjacencies[v].begin(); p != adjacencies[v].end(); p++) {
        if (!visited[*p]) {
            printAllPathsUtils(*p, e, visited, paths);
        }
    }
    }
    paths.pop_back();
    visited[v] = false;
}
void Graph::printAllPaths(int v, int e)
{
    bool* visited = new bool[V];
    std::vector<int> paths;
    printAllPathsUtils(v, e, visited, paths);
}
void Graph::printGraph()
{
    for (int i = 0; i < V; i++)
    {
        std::cout << "Adjacency list of vertex " << i << " is:" << std::endl;
        for (auto p = adjacencies[i].begin(); p != adjacencies[i].end(); p++)
        {
            std::cout << *p << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    /***
     * 0 ------ 1 ----- 4
     * |      /   \     |
     * |    /       \   |
     * |  /           \ |
     * 2----------3     5
     ***/

    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 1);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(4, 5);
    
    g.printGraph();
    std::cout << "----" << std::endl;
    g.printAllPaths(0, 4);
    return 0;
}