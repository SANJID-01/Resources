#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the number of process:";
    int n;
    cin >> n;

    vector<int> at(n), bt(n), ct(n), tat(n), wt(n), rt(n), pid(n);

    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        cout << "Enter the at and bt of process-" << i + 1 << " : ";
        cin >> at[i] >> bt[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }

    int time = 0;

    for (int i = 0; i < n; i++)
    {
        if (time < at[i])
            time = at[i];

        ct[i] = time + bt[i];
        time = ct[i];

        tat[i] = ct[i] - at[i];

        wt[i] = tat[i] - bt[i];

        rt[i] = wt[i];
    }

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "P-" << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\t" << rt[i] << endl;
    }

    return 0;
}
