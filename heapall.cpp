#include <iostream>
using namespace std;

void heapify(int a[], int n, int i, int maxHeap)
{
    int root = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (maxHeap)
    {
        if (l < n && a[l] > a[root])
            root = l;

        if (r < n && a[r] > a[root])
            root = r;
    }
    else
    {
        if (l < n && a[l] < a[root])
            root = l;

        if (r < n && a[r] < a[root])
            root = r;
    }

    if (root != i)
    {
        swap(a[i], a[root]);
        heapify(a, n, root, maxHeap);
    }
}

void heapSort(int a[], int n, int maxHeap)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i, maxHeap);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0, maxHeap);
    }
}

int main()
{
    int n, a[100], choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\n1. Ascending Order";
    cout << "\n2. Descending Order";
    cout << "\nEnter choice: ";
    cin >> choice;

    heapSort(a, n, choice == 1);

    cout << "Sorted elements: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
