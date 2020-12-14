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

template<typename T> void print_vector(vector<T> &vec, int start = 1) {

    int n = vec.size();
    for(int i = start; i < n; i++) {
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
 
        int N, K;
        cin >> N >> K;

        vector<int> a_vec(N+1, 0);

        int moving_sum = 0;
        for(int i = 1; i <= K; i++) {
            if(moving_sum - i > 0) {
                moving_sum -= i;
                a_vec[i] = -i;
            } else {
                moving_sum += i;
                a_vec[i] = i;
            }
        }

        for(int i = K+1; i <= N+1; i++) {
            a_vec[i] = -i;
        }
        // print_vector(a_vec);

        vector<int> prefixes(N+1, 0);
        prefixes[1] = a_vec[1];

        for(int i = 2; i < N+1; i++) {
            prefixes[i] = prefixes[i-1] + a_vec[i];
        
        }

        int nK = 0;
        for(int i = 1; i < N+1; i++)
            if(prefixes[i] > 0)
                nK++;


        if(nK != K) {
            cout << "Error for: " << K << "\n";
            print_vector(prefixes);
        } 


    }
}