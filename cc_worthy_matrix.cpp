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
 
        int N, M, K;
        cin >> N >> M >> K;

        vector<vector<ulli>> a_matrix(N, vector<ulli>(M, 0));

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> a_matrix[i][j];
            }
        }

        // cout << "--- --- ---" << endl;
        // print_matrix(a_matrix);

        vector<vector<ulli>> pre_comp(N, vector<ulli>(M, 0));
        for(int i = 0; i < N; i++) {
            // cout << "i: " << i << endl;
            int mi = i - 1;
            for(int j = 0; j < M; j++) {

                // cout << "j: " << j << endl;

                int mj = j - 1;

                ulli simj = 0;
                ulli smij = 0;
                ulli smimj = 0;

                if(mj >= 0) {
                    // cout << "mj: " << mj << endl;
                    simj = pre_comp[i][mj];
                }

                if(mi >= 0) {
                    // cout << "mi: " << mi << endl;
                    smij = pre_comp[mi][j];
                }

                if(mi >= 0 && mj >= 0) {
                    // cout << "mi: " << mi << " mj: " << mj << endl;
                    smimj = pre_comp[mi][mj];
                }

                pre_comp[i][j] = simj + smij + a_matrix[i][j] - smimj;

            }
        }

        // cout << "--- --- ---\n";
        // print_matrix(pre_comp);

        ulli res = 0;
        for(int side = 1; side <= min(N, M); side++) {
            for(int i = 0; i < N; i++) {
            
                int p = i;
                int r = p + side - 1;

                if(r >= N)
                    continue;

                int mp = p - 1;

                for(int j = 0; j < M; j++) {


                    int q = j;
                    int s = q + side - 1;

                    if(s >= M)
                        continue;

                    int mq = q - 1;

                    ulli srmq = 0;
                    ulli smps = 0;
                    ulli smpmq = 0;

                    if(mq >= 0)
                        srmq = pre_comp[r][q - 1];

                    if(mp >= 0)
                        smps = pre_comp[p - 1][s];

                    if(mp >= 0 && mq >= 0)
                        smpmq = pre_comp[p - 1][q - 1];

                    ulli local_sum = pre_comp[r][s] - srmq - smps + smpmq;

                    if(local_sum >= ulli(K)*ulli(side)*ulli(side)) {
                        // cout << "local_sum: " << local_sum << " avg: " << ld(local_sum) / (ld(side)*ld(side)) << endl;
                        res += 1;
                    }

                }
            }

        }
        cout << res << "\n";

    }


}