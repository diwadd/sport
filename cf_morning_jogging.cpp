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

    int N, M;
    cin >> N >> M;

    vector<int> b_ele(N*M, 0);
    vector<vector<int>> b_mat(N, vector<int>(M, 0));
    vector<int> front_index(N, 0);
    vector<int> back_index(N, M-1);

    int index = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {

            cin >> b_mat[i][j];
            b_ele[index] = b_mat[i][j];
            index++;
        }
    }

    for(int i = 0; i < N; i++) {
        sort(b_mat[i].begin(), b_mat[i].end());
    }

    sort(b_ele.begin(), b_ele.end());

    vector<vector<int>> res(N, vector<int>(M, 0));
    for(int i = 0; i <= M-1; i++) {

        int skip_index = 0;
        for(int j = 0; j <= N-1; j++) {

            int fi = front_index[j];

            if(b_mat[j][fi] == b_ele[i]) {

                res[j][i] = b_ele[i];
                front_index[j] += 1;
                skip_index = j;
                break;
            }
        }

        for(int j = 0; j <= N-1; j++) {
            if(j == skip_index)
                continue;


            int bi = back_index[j];

                    res[j][i] = b_mat[j][bi];
            back_index[j] -= 1;
        }
    }

    print_matrix(res);

    }
}