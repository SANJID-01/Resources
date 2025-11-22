#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the number of process:";
    int n;
    cin >> n;

    vector<int> at(n), bt(n), ct(n), tat(n), wt(n), pid(n), rem(n), rt(n, -1);

    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        cout << "Enter the at and bt of process-" << i + 1 << " : ";
        cin >> at[i] >> bt[i];
    }

    rem = bt;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(rem[i], rem[j]);
                swap(pid[i], pid[j]);
            }
        }
    }

    int completed = 0;
    int current_time = 0;

    while (completed < n)
    {
        int idx = -1;
        int mn = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (at[i] <= current_time && rem[i] > 0)
            {
                if (at[i] < mn)
                {
                    mn = at[i];
                    idx = i;
                }
            }
        }

        if (idx == -1)
        {
            current_time++;
            continue;
        }

        if (rt[idx] == -1)
        {
            rt[idx] = current_time - at[idx];
        }

        rem[idx]--;
        current_time++;

        if (rem[idx] == 0)
        {
            completed++;
            ct[idx] = current_time;
        }
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n";

    for (int i = 0; i < n; i++)
    {
        cout << "P-" << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\t" << rt[i] << "\t" << endl;
    }

    cout << "\nAverage TAT -> " << accumulate(tat.begin(), tat.end(), 0.0) / n << endl;
    cout << "\nAverage WAT -> " << accumulate(wt.begin(), wt.end(), 0.0) / n << endl;

    return 0;
}
