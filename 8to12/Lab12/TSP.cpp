#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int graph[4][4] = {
        {0,  20, 40, 30},
        {20, 0,  10, 60},
        {40, 10, 0,  50},
        {30, 60, 50, 0}
    };

    int cities[] = {1, 2, 3};

    int min_cost = 999999;
    int best_path[5];

    do {
        int path[5];

        path[0] = 0;

        for (int i = 0; i < 3; i++) {
            path[i + 1] = cities[i];
        }

        path[4] = 0;

        int cost = 0;

        for (int i = 0; i < 4; i++) {
            cost += graph[path[i]][path[i + 1]];
        }

        if (cost < min_cost) {
            min_cost = cost;

            for (int i = 0; i < 5; i++) {
                best_path[i] = path[i];
            }
        }

    } while (next_permutation(cities, cities + 3));

    char names[] = {'A', 'B', 'C', 'D'};

    cout << "Best Tour: ";

    for (int i = 0; i < 5; i++) {
        cout << names[best_path[i]];

        if (i < 4)
            cout << " -> ";
    }

    cout << endl;
    cout << "Minimum Cost: " << min_cost << endl;

    return 0;
}
