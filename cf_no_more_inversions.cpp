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

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int N, k;
        cin >> N >> k;
        vector<int> p_vec(k, 0);
        for(int i = 1; i < k - (N - k); i++) {
            p_vec[i-1] = i;
        }

        int index = k - (N - k) - 1;
        for(int i = k; i >= k - (N - k); i--) {
            p_vec[index] = i;
            index++;
        }

        print_vector(p_vec);

    }
}
