#include <iostream>

using namespace std;

int main()
{
    float balance[12];
    double sum = 0;

    for (int i = 0; i < 12; i++) {
        cin >> balance[i];
        sum = sum + balance[i];
    }

    cout << sum/12 << "\n";
    return 0;
}
