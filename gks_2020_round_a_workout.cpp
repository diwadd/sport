#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

void left_just(string &s, int n, char c = ' ') {
    while(s.length() < n) {
        s = c + s;
    }
}

template<typename T> void print_vector(vector<T> &vec) {

    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
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

    for(int t = 1; t <= T; t++) {

        int N, K;
        cin >> N >> K;
        
        vector<int> a_vec(N, 0);
        for(int i = 0; i < N; i++) {
            int ai;
            cin >> ai;
            a_vec[i] = ai;
        }


        int left = 1;
        int right = a_vec[N-1];

        while(left < right){

            int d_optimal = (left + right) / 2;
            int k_sum = 0;
            // cout << "Checking d_optimal = " << d_optimal << " l: " << left << " r: " << right << "\n";
            for(int i = 0; i < N-1; i++) {
                int di = a_vec[i+1] - a_vec[i];
                int ki = max(int(ceil(double(di) / double(d_optimal)) - 1), 0);
                k_sum += ki;
                // cout << "di: " << di << " ki: " << ki << "\n";
            }

            if(k_sum <= K){
                right = d_optimal;
            } else {
                left = d_optimal + 1;
            }
        }

        cout << "Case #" << t << ": " << right << "\n";


    }
}