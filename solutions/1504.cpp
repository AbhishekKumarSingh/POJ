#include <iostream>

using namespace std;

int reverse(int num) {
    int rem, rev = 0;
    while(num) {
        rem = num % 10;
        rev = rev * 10 + rem;
        num = num/10;
    }
    return rev;
}

int main() {
    int ntestcase, num1, num2, sum;
    cin >> ntestcase;

    for (int i = 0; i < ntestcase; i++) {
        cin >> num1 >> num2;
        sum = reverse(num1) + reverse(num2);
        cout << reverse(sum) << "\n";
    }

    return 0;
}
