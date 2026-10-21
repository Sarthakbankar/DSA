#include <iostream>
using namespace std;

int main() {
    int cost[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int visited[5] = {1, 0, 0, 0, 0};
    int edges = 0, total = 0;

    cout << "Minimum Spanning Tree:\n";

    while (edges < 4) {
        int min = 999, a = -1, b = -1;

        for (int i = 0; i < 5; i++) {
            if (visited[i]) {
                for (int j = 0; j < 5; j++) {
                    if (!visited[j] && cost[i][j] != 0 &&
                        cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        cout << a << " - " << b << " : " << min << endl;
        visited[b] = 1;
        total += min;
        edges++;
    }

    cout << "Total Cost: " << total;

    return 0;
}
