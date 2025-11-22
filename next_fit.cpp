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
    int temp = 0;

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

        for (int j = temp; j < n; j++)
        {
            if (v[j] >= sz)
            {
                v[j] -= sz;
                allocated = true;
                cout << "Process is allocated on block- " << j + 1 << endl;

                if (j == n - 1)
                    temp = 0;
                else
                    temp = j + 1;
                break;
            }
        }
        if (!allocated)
            cout << "Process has not enough space for allocation" << endl;
    }

    return 0;
}
