#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

template<typename T> void print_vector(vector<T> &vec) {
    for(auto v : vec) {
        cout << v << " ";
    }
    cout << "\n";
}

void print_map(map<int, int> &m) {
    for(auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " <-> " << it->second << "\n";
    }
}


int main() {

    const unsigned long long MOD7 = 1000000000+7;
    const unsigned long long MAX_NUMBERS = 200000 + 7;

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int N;
        cin >> N;

        vector<int> vec(N, 0);
        for(int i = 0; i < N; i++) {
            int S;
            cin >> S;
            vec[i] = S;
        }

        unsigned long long int sum  = 0;
        for(int i = 1; i < N; i++) {
            // cout << "abs(vec[i] - vec[i-1]): " << abs(vec[i] - vec[i-1]) - 1 << endl;
            sum = sum + abs(vec[i] - vec[i-1]) - 1;
        }

        cout << sum << "\n";
    }

}