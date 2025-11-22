#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, f;
    cout << "Enter the total number of pages: ";
    cin >> n;

    vector<int> pages(n);
    cout << "Enter the page numbers (separated by space): ";
    for (int i = 0; i < n; ++i)
        cin >> pages[i];

    cout << "Enter the number of frames: ";
    cin >> f;

    vector<int> frame(f, -1); // store page number or -1 if empty
    vector<int> refbit(f, 0); // reference bits (0 or 1)
    int pointer = 0;          // clock hand pointer
    int faults = 0;

    cout << "\nPage Replacement Process:\n\n";

    for (int i = 0; i < n; ++i)
    {
        int pg = pages[i];
        bool hit = false;

        // check hit
        for (int j = 0; j < f; ++j)
        {
            if (frame[j] == pg)
            {
                hit = true;
                refbit[j] = 1; // give second chance
                break;
            }
        }

        if (!hit)
        {
            // page fault: find victim using second chance (clock)
            // if there's empty frame, use it first
            bool placed = false;
            for (int j = 0; j < f; ++j)
            {
                if (frame[j] == -1)
                {
                    frame[j] = pg;
                    refbit[j] = 1;
                    placed = true;
                    break;
                }
            }

            if (!placed)
            {
                // use clock algorithm to find frame with refbit == 0
                while (true)
                {
                    if (refbit[pointer] == 0)
                    {
                        // replace this frame
                        frame[pointer] = pg;
                        refbit[pointer] = 1;         // set reference bit for new page
                        pointer = (pointer + 1) % f; // move clock hand to next position
                        break;
                    }
                    else
                    {
                        // give second chance: clear the refbit and move on
                        refbit[pointer] = 0;
                        pointer = (pointer + 1) % f;
                    }
                }
            }
            faults++;
        }

        // print current state in bracket format
        cout << "After inserting page " << pg << ": ";
        for (int j = 0; j < f; ++j)
        {
            if (frame[j] == -1)
                cout << "[" << " " << "] ";
            else
                cout << "[" << frame[j] << "] ";
        }
        cout << "\n";
    }

    cout << "\nTotal Page Faults = " << faults << "\n";
    cout << "Total Page Hits = " << (n - faults) << "\n";

    return 0;
}
