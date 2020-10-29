#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

template<typename T> void print_vector(vector<T> &vec) {

    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int N;
        cin >> N;
        vector<int> a_vec(N, 0);
        vector<int> a_vec_sorted(N, 0);

        for(int n = 0; n < N; n++) {
            int a;
            cin >> a;
            a_vec[n] = a;
            a_vec_sorted[n] = a;
        }

        sort(a_vec_sorted.begin(), a_vec_sorted.end());

        // print_vector(a_vec);

        int min_a = a_vec_sorted[0];
        int ok_positions = 0;
        vector<int> is_pos_ok(N, 0);
        for(int n = 0; n < N; n++) {
            if(a_vec_sorted[n] == a_vec[n]){
                ok_positions++;
                is_pos_ok[n] = 1;
            }
        }

        if(ok_positions == N) {
            cout << "YES\n";
            continue; 
        }

        bool is_ok = true;
        for(int n = 0; n < N; n++) {
            if(is_pos_ok[n] == 0) {
                if(a_vec[n] % min_a != 0) {
                    is_ok = false;
                    break;
                }
            }
        }

        if(is_ok == true) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
}