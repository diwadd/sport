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
 
        int N;
        cin >> N;
 
        vector<int> p_vec(N, 0);
        for(int i = 0; i < N; i++) {
            p_vec[i] = N - i;
        }
 
        if(N % 2 == 0) {
            print_vector(p_vec);
        } else {
            int mid = floor(N / 2);
            int q = p_vec[mid];
            p_vec[mid] = p_vec[0];
            p_vec[0] = q;
            print_vector(p_vec);
        }
    }
}
 