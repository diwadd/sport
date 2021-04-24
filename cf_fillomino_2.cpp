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
    
        int n = mat[i].size();
        for(int j = 0; j < n; j++) {
            if (j <= i) {
    
                if(j == n - 1)
                    cout << mat[i][j];
                else
                    cout << mat[i][j] << " ";
    
            }
    
        }
        cout << "\n";
    
    }
}
    
    
int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> p_vec(N, 0);
    
    for(int i = 0; i < N; i++) {
        cin >> p_vec[i];
    }
    
    vector<vector<int>> board(N, vector<int>(N, 0));
    
    for(int i = 0; i < N; i++) {
        board[i][i] = p_vec[i];
    }
    
    for(int i = 0; i < N; i++) {
    
        int x = board[i][i];
        if(x == 1) {
            continue;
        }
    
        int p_row = i;
        int p_col = i;
        int moves_made = 1;
        bool is_ok = true;
        while (moves_made < x) {
    
            bool l_move = false;
            int l_row = p_row;
            int l_col = p_col - 1;
    
            bool d_move = false;
            int d_row = p_row + 1;
            int d_col = p_col; 
    
    
            if(l_row <= N - 1 && l_col <= N - 1)
                l_move = true;
            
            if(d_row <= N - 1 && d_col <= N - 1)
                d_move = true;
    
            if(l_move == true && board[l_row][l_col] == 0) {
                board[l_row][l_col] = x;
                moves_made++;
                p_row = l_row;
                p_col = l_col;
            } else if(d_move == true && board[d_row][d_col] == 0) {
                board[d_row][d_col] = x;
                moves_made++;
                p_row = d_row;
                p_col = d_col;
            } else {
                is_ok = false;
                break;
            }
        }
    }
    
    print_matrix(board);
    
}