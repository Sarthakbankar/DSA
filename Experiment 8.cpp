#include <iostream>
using namespace std;

int main() {
    int hash[10];

    for (int i = 0; i < 10; i++)
        hash[i] = -1;

    int n, key, index;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter key: ";
        cin >> key;

        index = key % 10;

        while (hash[index] != -1)
            index = (index + 1) % 10;

        hash[index] = key;
    }

    cout << "\nHash Table:\n";

    for (int i = 0; i < 10; i++)
        cout << i << " -> " << hash[i] << endl;

    return 0;
}
