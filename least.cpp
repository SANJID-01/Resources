#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, f;
    cout << "Enter number of pages: ";
    cin >> n;
    vector<int> pages(n);
    cout << "Enter the page reference string: ";
    for (int i = 0; i < n; ++i)
        cin >> pages[i];
    cout << "Enter number of frames: ";
    cin >> f;

    vector<int> frame(f, -1);
    vector<int> lastUsed(f, -1);
    int faults = 0;

    cout << "\nPage Replacement Process:\n\n";
    for (int i = 0; i < n; ++i)
    {
        int pg = pages[i];
        bool hit = false;

        for (int j = 0; j < f; ++j)
        {
            if (frame[j] == pg)
            {
                hit = true;
                lastUsed[j] = i; // update last used time (index)
                break;
            }
        }

        if (!hit)
        {
            // if empty slot exists, use it
            bool placed = false;
            for (int j = 0; j < f; ++j)
            {
                if (frame[j] == -1)
                {
                    frame[j] = pg;
                    lastUsed[j] = i;
                    placed = true;
                    break;
                }
            }
            if (!placed)
            {

                int victim = 0;
                int minTime = lastUsed[0];
                for (int j = 1; j < f; ++j)
                {
                    if (lastUsed[j] < minTime)
                    {
                        minTime = lastUsed[j];
                        victim = j;
                    }
                }

                frame[victim] = pg;
                lastUsed[victim] = i;
            }
            faults++;
        }

        cout << "After inserting page " << pg << ": ";
        for (int j = 0; j < f; ++j)
        {
            if (frame[j] == -1)
                cout << "[ ] ";
            else
                cout << "[" << frame[j] << "] ";
        }
        cout << (hit ? " Hit\n" : " Fault\n");
    }

    cout << "\nTotal Page Faults = " << faults << "\n";
    cout << "Total Page Hits = " << (n - faults) << "\n";
    return 0;
}
