#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
 
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
 
    for(int t = 0; t < T; t++) {
 
        int N;
        cin >> N;

        vector<vector<int>> matrix(N, vector<int>(N, 0));

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> matrix[i][j];
            }
        }

        bool is_ok = true;
        int start_index = N-1;
        for(int i = N-1; i >= 1; i--) {
            if(matrix[0][i] != i + 1) {
                start_index = i;
                is_ok = false;
                break;
            }
        }

        if(is_ok == true){
            cout << "0\n";
            continue;
        }

        int boxes = 0;
        bool diff = false;
        for(int i = start_index; i >= 1; i--) {
            if(matrix[0][i] != i+1) {
                boxes++;
                for(int j = i-1; j >= 0; j--) {
                    if(matrix[0][j] != j+1) {
                        i--;
                        continue;
                    } else {
                        i = j + 1;
                        break;
                    }
                }
            } else if(matrix[0][i] == i+1) {
                boxes++;
                for(int j = i-1; j >= 0; j--) {
                    if(matrix[0][j] == j+1) {
                        i--;
                        continue;
                    } else {
                        i = j + 1;
                        break;
                    }
                }   
            }

        }

        cout << boxes << "\n";

    }
}