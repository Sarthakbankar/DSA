#include <iostream>
using namespace std;

int a[5][5], visited[5];

void DFS(int v, int n) {
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (a[v][i] == 1 && visited[i] == 0)
            DFS(i, n);
    }
}

int main() {
    int n = 5;

    a[0][1] = a[1][0] = 1;
    a[0][2] = a[2][0] = 1;
    a[1][3] = a[3][1] = 1;
    a[1][4] = a[4][1] = 1;

    cout << "DFS Traversal: ";
    DFS(0, n);

    return 0;
}
