#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;


template<typename T> void print_vector_of_vectors(vector<vector<T>> &v) {

    for(int i = 0; i< v.size(); i++){
        
        cout << i << ":\n";
        for(int j = 0; j < v[i].size(); j++){

            cout << v[i][j] << " ";

        }

        cout << "\n";
    }
}

template<typename T> void print_vector(vector<T> &v) {

    for(int i = 0; i< v.size(); i++){

        cout << i << ": " << v[i] << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int N, M;
        cin >> N;
        cin >> M;

        vector<vector<int>> a_matrix(N, vector<int>(M, 0));

        for(int n = 0; n < N; n++) {
            for(int m = 0; m < M; m++) {
                int a;
                cin >> a;
                a_matrix[n][m] = a;
            }
        }


        vector<int> ones(N + M - 1, 0);
        vector<int> zeros(N + M - 1, 0);

        for(int n = 0; n < N; n++) {
            for(int m = 0; m < M; m++) {

                if(a_matrix[n][m] == 0) {
                    zeros[n + m]++;
                } else {
                    ones[n + m]++;
                }

            }
        }

        int w = ones.size();
        int counter = 0;
        for(int i = 0; i < w / 2; i++) {

            int no = ones[i] + ones[w - i - 1];
            int nz = zeros[i] + zeros[w - i - 1];
            counter = counter + min(no, nz);

        }


        cout << counter << "\n";

    }
}