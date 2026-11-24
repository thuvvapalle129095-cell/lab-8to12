#include <iostream>
using namespace std;

int main() {

    const int INF = 999;

    int graph[3][3] = {
        {0,   2,   3},
        {INF, 0,   1},
        {INF, INF, 0}
    };

    int dist[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {

                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }

            }
        }
    }

    cout << "Shortest Distance Matrix:" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
