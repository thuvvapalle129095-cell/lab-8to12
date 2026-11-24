#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    char u, v;
    int weight;
};

int parent[4];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int a, int b) {
    parent[find(a)] = find(b);
}

int main() {
    Edge graph[] = {
        {'A', 'B', 2},
        {'A', 'D', 1},
        {'D', 'C', 3},
        {'B', 'C', 6}
    };

    int n = 4;
    int edges = 4;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    sort(graph, graph + edges,
         [](Edge a, Edge b) {
             return a.weight < b.weight;
         });

    int total = 0;

    cout << "MST Edges:" << endl;

    for (int i = 0; i < edges; i++) {
        int u = graph[i].u - 'A';
        int v = graph[i].v - 'A';

        if (find(u) != find(v)) {
            unionSet(u, v);

            cout << graph[i].u << " - "
                 << graph[i].v << " : "
                 << graph[i].weight << endl;

            total += graph[i].weight;
        }
    }

    cout << "Minimum Cost: " << total << endl;

    return 0;
}
