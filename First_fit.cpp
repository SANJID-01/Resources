#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of memory block : ";
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter memory size of block- " << i + 1 << ": ";
        cin >> v[i];
    }

    while (true)
    {
        cout << "Enter the process size( 0 -> exit) : ";
        int sz;
        bool allocated = false;
        cin >> sz;

        if (sz == 0)
        {
            cout << "Program is terminated!!" << endl;
            break;
        }

        for (int i = 0; i < n; i++)
        {
            if (v[i] >= sz)
            {
                v[i] -= sz;
                allocated = true;
                cout << "Process is allocated on block- " << i + 1 << endl;
                break;
            }
        }
        if (!allocated)
            cout << "Process has not enough space for allocation" << endl;
    }

    return 0;
}
