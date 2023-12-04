#include <iostream>
#include <string>
using namespace std;

void is_prime(int a) {

    if (a == 1)
        cout << "not prime " << endl;

    int i = 2;

    while (i <= a / i) {
        if ((a % i == 0) && (i != a)) {
            cout << "not prime " << endl;
            return;
        }
        i++;
    }
    cout << "prime " << endl;
}
