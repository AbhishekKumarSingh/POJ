// This algorithm is more efficient than previous. It runs in sqrt(N) time.

#include <iostream>
#include <cmath>

using namespace std;

int num_ways(int num) {
    int count = 0;
    for (int i = 1; i <= sqrt(double(2*num)); i++) {
        if ((2*num - (i*(i-1))) % (2*i) == 0)
            count++;
    }
    return count;
}


int main()
{
    int num;
    cin >> num;
    cout << num_ways(num) << "\n";
    return 0;
}
