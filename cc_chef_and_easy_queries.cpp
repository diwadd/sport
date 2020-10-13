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

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        lli N, K;
        cin >> N >> K;

        vector<lli> q_vec(N, 0);
        for(lli n = 0; n < N; n++)
            cin >> q_vec[n];


        lli carry = 0;
        lli free_day = -1;
        lli used_days = 0;
        for(int n = 0; n < N; n++) {
            if(q_vec[n] + carry < K) {
                // cout << n + 1 << "\n";
                free_day = n + 1;
                break;
            }

            carry = max(q_vec[n] + carry - K, lli(0));
            used_days += 1;
        }

        // cout << "carry: " << carry << "\n";
        if(free_day == -1) {
            lli n_days = used_days + (carry / K) + 1;
            cout << n_days << "\n";
        } else {
            cout << free_day << "\n";
        }


    }


}