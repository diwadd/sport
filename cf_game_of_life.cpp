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
            cout << vec[i];
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
 
        int N, M;
        cin >> N >> M;

        string s;
        vector<int> c_arr(N, 0);

        cin >> s;

        for(int i = 0; i < N; i++) {
            c_arr[i] = s[i] - '0';
        }

        bool is_different = true;
        vector<int> c_next(c_arr.begin(), c_arr.end());

        int it = 0;
        while(is_different == true && it < M) {

            // cout << "--- --- ---\n";
            // cout << "it: " << it << endl;
            // print_vector(c_arr);
            // print_vector(c_next);
            for(int i = 0; i < N; i++) {

                if(i == 0) {
                    if(c_arr[i] == 0 && c_arr[i+1] == 1) {
                        c_next[i] = 1;
                    }
                } else if(i == N-1) {
                    if(c_arr[i] == 0 && c_arr[i-1] == 1) {
                        c_next[i] = 1;
                    }
                } else {
                    if(c_arr[i] == 0 && (c_arr[i-1] == 1 and c_arr[i+1] == 1)) {
                        continue;
                    } else if(c_arr[i] == 0 && (c_arr[i-1] == 1 || c_arr[i+1] == 1)) {
                        c_next[i] = 1;
                    } else if(c_arr[i] == 0 && (c_arr[i-1] != 1 && c_arr[i+1] != 1)) {
                        continue;
                    }
                }

            }

            if(c_arr == c_next) {
                is_different = false;
            } else {
                is_different = true;
            }
            c_arr = c_next;
            it++;

        }

        print_vector(c_arr);
        // cout << it << "\n";

    }


}