#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void left_just(string &s, int n, char c = ' ') {
    while(s.length() < n) {
        s = c + s;
    }
}

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

template<typename T> void print_matrix(vector<vector<T>> &mat) {
    for(int i = 0; i < mat.size(); i++) {
        print_vector(mat[i]);
    }
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // auto start = chrono::steady_clock::now();
    
    int MAX_PRIMES = 4000000;
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

    // cout << "n_primes: " << n_primes << endl;
    vector<int> primes(n_primes, 0);
    int index = 0;
    for(int i = 0; i < MAX_PRIMES; i++) {
        if(sieve[i] == 1) {
            primes[index] = i;
            index++;
        }
    }

    // auto end = chrono::steady_clock::now();
    // chrono::duration<double> elapsed_seconds = end-start;
    // cout << "time: " << elapsed_seconds.count() << "s\n";

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int N;
        cin >> N;

        vector<int> b_vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> b_vec[i];
        }


        vector<int> a_vec(N, 0);
        for(int i = 0; i < N; i++) {
            a_vec[i] = primes[b_vec[i]-1];
        }


        print_vector(a_vec);
    }


}