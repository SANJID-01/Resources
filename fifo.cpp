#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the number of pages:";
    int n;
    cin >> n;

    vector<int> pages(n);
    cout << "Enter the number of pages with seperated space : ";

    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter the number of frame: ";
    int f;
    cin >> f;

    vector<int> frame(f, -1);

    int pointer = 0;
    int miss = 0;

    for (int i = 0; i < n; i++)
    {
        bool hit = false;
        int pg = pages[i];

        // ai part hit check er jonno
        for (int j = 0; j < f; j++)
        {
            if (frame[j] == pg)
            {
                hit = true;
                break;
            }
        }

        // ai part miss er jonno
        if (hit == false)
        {
            frame[pointer] = pg;
            pointer = (pointer + 1) % f;
            miss++;
        }

        cout << "\nAfter inserted " << pg << " frame-> ";

        for (int j = 0; j < f; j++)
        {
            if (frame[j] == -1)
            {
                cout << "_ ";
            }
            else
            {
                cout << frame[j] << " ";
            }
        }
    }

    cout << "\n\nNumber of miss-> " << miss << endl;
    cout << "\nNumber of hit-> " << n - miss << endl;

    return 0;
}