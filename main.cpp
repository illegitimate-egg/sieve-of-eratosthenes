#include <bitset>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
 
bitset<4949672952> Primes;
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

ofstream primeFile("primes.txt");

void fileCloser( int signum ) {
    primeFile.close();
    exit(signum);
}

int main(int argc, char *argv[])
{
    unsigned long long int n;
    int output;
    if (argc > 1)
    {
        n = stoll(argv[1]);
        output = stoi(argv[2]);
    } else {
        cout << "Enter limit: ";
        cin >> n;
        cout << "(0): No output\n(1): Echoed output\n(2): Saved output (primes.txt)\n(3): RAM Save (primes.txt)\nOutput type: ";
        cin >> output;
    }

    SieveOfEratosthenes(n);
    if (output == 1) {
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
    } else if (!output) {
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
    } else if (output == 2) {
        for (int i = 1; i <= n; i++) {
            if (i == 2) {
                foundPrimes++;
                primeFile << i << '\n';
            }
            else if (i % 2 == 1 && Primes[i / 2] == 0) {
                foundPrimes++;
                primeFile << i << '\n';
            }
        }
    } else if (output == 3) {
        vector<int> stored;
        for (int i = 1; i <= n; i++) {
            if (i == 2) {
                foundPrimes++;
                stored.push_back(i);
            }
            else if (i % 2 == 1 && Primes[i / 2] == 0) {
                foundPrimes++;
                stored.push_back(i);
            }
        }
        for(int i=0; i < stored.size(); i++) {
            primeFile << to_string(stored[i]) << '\n';
        }
    } else {
        cout << "Invalid output level" << endl;
    }

    primeFile.close();

    cout << "Number of primes found: " << to_string(foundPrimes) << endl;
    return 0;
}
