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

        vector<string> s_vec(N, string(M, '*'));
        for(int i = 0; i < N; i++) {
            string s;
            cin >> s;
            s_vec[i] = s;
        }

        vector<vector<int>> lt_vec(N, vector<int>(M, 0));
        vector<vector<int>> rt_vec(N, vector<int>(M, 0));
        for(int i = 0; i < N; i++) {

                int series = 0;
                for(int j = 0; j < M; j++) {
                    
                    if(s_vec[i][j] == '*') {
                        series++;
                        lt_vec[i][j] = series;
                    } else if (s_vec[i][j] == '.') {
                        series = 0;
                    }
                }

                series = 0;
                for(int j = M-1; j >= 0; j--) {
                    
                    if(s_vec[i][j] == '*') {
                        series++;
                        rt_vec[i][j] = series;
                    } else if (s_vec[i][j] == '.') {
                        series = 0;
                    }
                }
        }


        vector<vector<int>> length_mat(N, vector<int>(M, 0));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                length_mat[i][j] = min(lt_vec[i][j], rt_vec[i][j]);
            }
        }

        // print_matrix(length_mat);

        int res = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(s_vec[i][j] == '.') {
                    continue;
                } else {
                    res++;
                    int req_h = 2;
                    for(int k = i+1; k < N; k++) {
                        if(length_mat[k][j] >= req_h) {
                            req_h++;
                            res++;
                        } else {
                            break;
                        }
                    }

                }
            }
        }


        // print_matrix(length_mat);
        cout << res << "\n";
    }
}