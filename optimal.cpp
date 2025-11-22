#include <bits/stdc++.h>
using namespace std;

int main()
{
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
    int faults = 0;

    cout << "\nPage Replacement Process:\n\n";
    for (int i = 0; i < n; ++i)
    {
        int pg = pages[i];
        bool hit = false;
        for (int j = 0; j < f; ++j)
            if (frame[j] == pg)
            {
                hit = true;
                break;
            }

        if (!hit)
        {
            bool placed = false;
            for (int j = 0; j < f; ++j)
            {
                if (frame[j] == -1)
                {
                    frame[j] = pg;
                    placed = true;
                    break;
                }
            }
            if (!placed)
            {
                int victim = -1;
                int farthest = -1;
                for (int j = 0; j < f; ++j)
                {
                    int nextUse = INT_MAX;
                    for (int k = i + 1; k < n; ++k)
                    {
                        if (pages[k] == frame[j])
                        {
                            nextUse = k;
                            break;
                        }
                    }
                    if (nextUse > farthest)
                    {
                        farthest = nextUse;
                        victim = j;
                    }
                }
                frame[victim] = pg;
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
