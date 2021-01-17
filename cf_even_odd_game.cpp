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
 
        int N;
        cin >> N;

        vector<lli> a_vec(N, 0);
        lli odd = 0;
        lli even = 0;
        for(int i = 0; i < N; i++) {
            cin >> a_vec[i];
            if(a_vec[i] % 2 == 0)
                even++;
            else
                odd++;
        }

        sort(a_vec.rbegin(), a_vec.rend());
        // print_vector(a_vec);

        bool a_move = true;
        lli score = 0;
        for(int i = 0; i < N; i++) {
            if(a_vec[i] % 2 == 0) {
                if(a_move == true) {
                    score += a_vec[i];
                    a_move = false;
                } else {
                    a_move = true;
                }
            } else {
                if(a_move == false) {
                    score -= a_vec[i];
                    a_move = true;
                } else {
                    a_move = false;
                }
            }
        }

        if(score > 0)
            cout << "Alice\n";
        else if (score == 0)
            cout << "Tie\n";
        else
            cout << "Bob\n";

    }


}