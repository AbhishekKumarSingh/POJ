#include <iostream>
#include <vector>

using namespace std;

int main()
{
    float input, res;
    int ncard = 0, i, count;
    vector<int> card;

    while(true) {
        cin >> input;
        if (input == 0.00) break;
        res = input;
        i = 2; count = 0;
        while(res >= 0.00) {
            res = res - (1.0/i);
            i++;
            count++;
        }

        card.push_back(count);
    }

    i = 0;
    while(i < card.size()) {
        cout << card[i++] << " card(s)\n";
    }
    return 0;
}
