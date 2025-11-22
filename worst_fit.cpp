#include <bits/stdc++.h>
using namespace std;

int main()
{
    // sonic;

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

        int b_index = -1;

        for (int i = 0; i < n; i++)
        {
            if (v[i] >= sz)
            {
                if (b_index = -1 || v[i] > v[b_index])
                    b_index = i;
            }
        }

        if (b_index != -1)
        {
            v[b_index] -= sz;
            cout << "Process is allocated on block- " << b_index + 1 << endl;
        }
        else
            cout << "Process has not enough space for allocation" << endl;
    }

    return 0;
}
