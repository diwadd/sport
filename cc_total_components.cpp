#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int MAX_N = 10000000 + 7;
    vector<int> sieve(MAX_N+1, 0);
    vector<int> numbers(MAX_N+1, 0);
    numbers[0] = 0;
    numbers[1] = 0;
    numbers[2] = 1;
    int running_set = 1;
    for(int n = 2; n <= MAX_N; n++) {

        if(sieve[n] == 1) {
            numbers[n] = numbers[n-1];
            continue;
        } else {
            numbers[n] = numbers[n-1] + 1;
        }

        for(int j = n; j <= MAX_N; j = j + n) {
            sieve[j] = 1;
        }
    }

    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {

        int N;
        cin >> N;

        if(N == 2){
            cout << 1 << "\n";
        } else if(N == 3) {
            cout << 2 << "\n";
        } else {
            cout << numbers[N] - numbers[N/2] + 1 << "\n";
        }

    }


}