#include <iostream>
#include <list>
#include <vector>

class Graph
{
private:
    int V;                      // number of vertices
    std::list<int>* adjacencies;     // array of adjacency lists
    bool count_cycle_utils(int v, int parent, bool visited[], int& count);
    void print_all_paths_utils(int v, bool visited[], std::vector<int>& paths, bool& has_cycle);
    bool all_is_visited(int v, bool visited[]);
public:
    Graph(int V): V(V) {
        adjacencies = new std::list<int>[V];
    }
    void addEdge(int src, int dst) {
        adjacencies[src].push_back(dst);
        adjacencies[dst].push_back(src);
    }
    int count_cycle();            // returns true if graph contains cycles
    void print_all_paths_from(int v);
};
void print_path(std::vector<int>& path);
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

    g.print_all_paths_from(0);

    /**
     * 0 -------- 1 ---------- 2
     **/

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);

    return 0;
}

/****** GRAPH DEFINITION ********/

void Graph::print_all_paths_utils(int v, bool visited[], std::vector<int>& paths, bool& has_cycle)
{
    // mark v as visited
    visited[v] = true;
    // add v to path
    paths.push_back(v);

    // if we reach the end node, print the path
    if (all_is_visited(v, visited)) {
        std::cout << "found a path: ";
        if (has_cycle) std::cout << "(cyclic) ";
        print_path(paths);
    }
    else {
        // continue with vertice v's adjacency list
        for (auto p = adjacencies[v].begin(); p != adjacencies[v].end(); p++) {
            if (!visited[*p]) print_all_paths_utils(*p, visited, paths, has_cycle);
            else has_cycle = true;
        }
    }
    // after printing the path, go back one vertice
    // by popping out the last vertice
    // and marking it as unvisited
    paths.pop_back();
    visited[v] = false;
    has_cycle = false;
}
void Graph::print_all_paths_from(int v)
{
    bool* visited = new bool[V];
    std::vector<int> paths;
    bool has_cycle;
    print_all_paths_utils(v, visited, paths, has_cycle);
}

// use DFS to traverse from start vertice
// if a vertice has a visited adjcent vertice that's not its parent
// the graph has cycle
int Graph::count_cycle()
{
    bool* visited = new bool[V];
    int cycle_count = 0;
    if(count_cycle_utils(0, -1, visited, cycle_count)) {
        return cycle_count;
    }
    return 0;
}

bool Graph::count_cycle_utils(int v, int parent, bool visited[], int& count)
{
    visited[v] = true;
    for (auto p = adjacencies[v].begin(); p != adjacencies[v].end(); p++) {
        if (!visited[*p]) {
            if(count_cycle_utils(*p, v, visited, count)) count++;
        }
        else if (visited[*p] && *p != parent) {
            return true;
        }
    }
    return false;
}

/************************ UTILITIES *************************/
bool Graph::all_is_visited(int v, bool visited[])
{
    bool all = true;
    for (auto p = adjacencies[v].begin(); p != adjacencies[v].end(); p++) {
        if (!visited[*p]) all = false;
    }
    return all;
}

void print_path(std::vector<int>& path)
{
    for (auto i = path.begin(); i != path.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}