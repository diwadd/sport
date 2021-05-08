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
        // string s = to_string(vec[i]);
        // left_just(s, 4);
        if(i == n - 1) {
            cout << vec[i];
        } else {
            cout << vec[i] << " ";
        }
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

        if(N == 2) {
            cout << -1 << "\n";
            continue;
        }

        vector<vector<int>> matrix(N, vector<int>(N, 0));

        int running_number = 1;
        for(int i = 0; i < N; i++) {

            int start_index;
            if(i % 2 == 0) {
                start_index = 0;
            } else {
                start_index = 1;
            }

            for(int j = start_index; j < N; j += 2) {
                matrix[i][j] = running_number;
                running_number++;
            }

        }

        for(int i = 0; i < N; i++) {

            int start_index;
            if(i % 2 == 0) {
                start_index = 1;
            } else {
                start_index = 0;
            }

            for(int j = start_index; j < N; j += 2) {
                matrix[i][j] = running_number;
                running_number++;
            }

        }

        print_matrix(matrix);




    }


}