#include <bitset>
#include <iostream>
using namespace std;
 
bitset<4294967295> Primes;
unsigned long int foundPrimes = 0;
void SieveOfEratosthenes(int n)
{
    Primes[0] = 1;
    for (int i = 3; i*i <= n; i += 2) {
        if (Primes[i / 2] == 0) {
            for (int j = 3 * i; j <= n; j += 2 * i)
                Primes[j / 2] = 1;
        }
    }
}
 
int main()
{

    unsigned long long int n;
    int output;
    cout << "Enter limit: ";
    cin >> n;
    cout << "Would you like to print output? (1/0) ";
    cin >> output;
    SieveOfEratosthenes(n);
    if (output) {
        for (int i = 1; i <= n; i++) {
            if (i == 2) {
                foundPrimes++;
                cout << i << '\n';
            }
            else if (i % 2 == 1 && Primes[i / 2] == 0) {
                foundPrimes++;
                cout << i << '\n';
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (i == 2) {
                foundPrimes++;
            }
            else if (i % 2 == 1 && Primes[i / 2] == 0) {
                foundPrimes++;
            }
        }
    }


    cout << "Number of primes found: " << to_string(foundPrimes) << endl;
    return 0;
}
