#include <prime.h>
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    int number = std::atoi(argv[1]);
    cout << "Number: " << number << endl;
    if (number <= 2) {
        cout << "It's not a prime number, error!" << endl;
        return 0;
    }
    int neighbour;
    neighbour = num_primes(number);
    cout << "Number of prime neighbours: " << neighbour << endl;
    return 0;

}