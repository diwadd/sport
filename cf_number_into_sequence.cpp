#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

template<typename T> void print_vector(vector<T> &vec) {

    int n = vec.size();
    for(int i = 0; i < n; i++) {
        if(i == n - 1)
            cout << vec[i];
        else
            cout << vec[i] << " ";
    }
    cout << "\n";
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int MAX_PRIMES = 200000;
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
 
        lli N;
        cin >> N;

        map<lli, lli> factors;
        lli nN = N;
        lli sqrtN = ceil(sqrt(N));
        for(lli i = 0; i < primes.size(); i++) {

            lli p = lli(primes[i]);
            if(p > sqrtN) {
                break;
            }
            
            while(nN % p == 0) {
                nN = nN / p;
                factors[p]++;
            }
        }

        if(nN != 1) {
            factors[nN]++;
        }

        if(factors.size() == 0) {
            cout << "1\n" << N << "\n";
            continue;
        }

        lli max_k = numeric_limits<lli>::min();
        lli max_factor = -1;
        for(auto it = factors.begin(); it != factors.end(); it++) {
            if(it->second > max_k){
                max_k = it->second;
                max_factor = it->first;
            }
        }

        vector<lli> res(max_k, max_factor);
        for(auto it = factors.begin(); it != factors.end(); it++) {
            if(it->first == max_factor){
                continue;
            } else {
                res[max_k-1] = res[max_k-1]*lli(pow(it->first, it->second));
            }
        }

        cout << max_k << "\n";
        print_vector(res);
    }
}