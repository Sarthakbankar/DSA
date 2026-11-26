#include <iostream>
using namespace std;

int main()
{
    int n, key[20], index[20];

    cout << "Enter number of records: ";
    cin >> n;

    cout << "Enter record keys:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> key[i];
        index[i] = i;
    }

    int search;
    cout << "Enter key to search: ";
    cin >> search;

    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        if (key[index[i]] == search)
        {
            cout << "Record found at position " << index[i] + 1;
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        cout << "Record not found";

    return 0;
}
