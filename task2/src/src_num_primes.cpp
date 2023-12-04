#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_prime(int a) {

    if (a == 1)
        return false;

    int i = 2;

    while (i <= a / i) {
        if ((a % i == 0) && (i != a)) {
            return false;
        }
        i++;
    }
    return true;
}

int num_primes(int num)
{
    std::vector<bool> is_prime(num + 1, true);
    is_prime[0] = is_prime[1] = false;
    int count = 0;

    for (int p = 2; p * p <= num; p++)
    {
        if (is_prime[p])
        {
            for (int i = p * p; i <= num; i += p)
            {
                is_prime[i] = false;
            }
        }
    }

    for (int i = 2; i <= num; i++) {
        if (is_prime[i]) {
            count++;
        }
    }

    return count;
}

