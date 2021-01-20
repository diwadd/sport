#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int MAX_PRIMES = 21000;
    vector<int> sieve(MAX_PRIMES, 1);
    sieve[0] = 0;
    sieve[1] = 0;

    int border = int(sqrt(double(MAX_PRIMES)))+1;
    for(int i = 0; i < border; i++) {
        if (sieve[i] == 0)
            continue;
        for(int j = 2*i; j < MAX_PRIMES; j = j + i) {
            sieve[j] = 0;
        }
    }

    int n_primes = 0;
    for(int i = 0; i < MAX_PRIMES; i++) {
        if(sieve[i] == 1) {
            n_primes++;
        }
    }

    vector<int> primes(n_primes, 0);
    int index = 0;
    for(int i = 0; i < MAX_PRIMES; i++) {
        if(sieve[i] == 1) {
            primes[index] = i;
            index++;
        }
    }

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int d;
        cin >> d;

        int it1 = 0;
        int index = 0;
        int it2 = 0;
        for(int i = 0; i < primes.size(); i++) {
            if(primes[i] - 1 >= d) {
                it1 = primes[i];
                index = i;
                break;
            }
        }

        for(int i = index; i < primes.size(); i++) {
            if(primes[i] - it1 >= d) {
                it2 = primes[i];
                break;
            }
        }

        cout << it1*it2 << "\n";
    }


}