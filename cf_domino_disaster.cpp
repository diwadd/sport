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

        string row;
        cin >> row;

        string new_row(N, '_');

        for(int i = 0; i < N; i++) {
            if(row[i] == 'U'){
                new_row[i] = 'D';
            } else if(row[i] == 'D') {
                new_row[i] = 'U';
            } else {
                new_row[i] = row[i];
            }
        }

        cout << new_row << "\n";

    }


}