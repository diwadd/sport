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
 
        int n, x;
        cin >> n >> x;

        vector<int> w_vec(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> w_vec[i];
        }


        sort(w_vec.begin(), w_vec.end());

        int sum = 0;
        bool is_ok = true;
        for(int i = 0; i < n; i++) {
            if(sum + w_vec[i] != x) {
                sum += w_vec[i];
            } else if (sum + w_vec[i] == x) {
                int box = w_vec[n-1];
                if(sum + box > x) {
                    swap(w_vec[i], w_vec[n-1]);
                    break;
                } else {
                    is_ok = false;
                    break;
                }
            }
        }

        if(is_ok == true) {
            cout << "YES\n";
            print_vector(w_vec);
            continue;
        }

        sort(w_vec.rbegin(), w_vec.rend());

        sum = 0;
        is_ok = true;
        for(int i = 0; i < n; i++) {
            if(sum + w_vec[i] != x) {
                sum += w_vec[i];
            } else if (sum + w_vec[i] == x) {
                int box = w_vec[n-1];
                if(sum + box > x) {
                    swap(w_vec[i], w_vec[n-1]);
                    break;
                } else {
                    is_ok = false;
                    break;
                }
            }
        }

        if(is_ok == true) {
            cout << "YES\n";
            print_vector(w_vec);
        } else {
            cout << "NO\n";
        }


    }


}