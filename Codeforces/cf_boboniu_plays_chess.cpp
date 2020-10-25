#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);



    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;

    int px = sx;
    int py = sy;

    vector<vector<int>> board(n+1, vector<int>(m+1, 0));

    board[px][py] = 1;
    cout << px << " " << py << "\n";
    board[0][py]++;
    board[px][0]++;

    int n_high = 1;
    int n_low = n;

    int m_left = 1;
    int m_right = m;

    char v = 'B';
    char h = 'L';
    int seen_tiles = 1;

    while(seen_tiles < n * m) {

        m_left = 1;
        m_right = m;
        while( board[px][0] < m ) {
            
            if(h == 'L') {
                while(true) {
                    if(board[px][m_left] == 0) {
                        board[px][m_left] = 1;
                        seen_tiles++;
                        board[px][0]++;
                        board[0][m_left]++;
                        py = m_left; 
                        break;
                    } else {
                        m_left = m_left + 1;
                    }
                }
                cout << px << " " << m_left << "\n";
                h = 'R';
            } else {
                while(true) {
                    if(board[px][m_right] == 0) {
                        board[px][m_right] = 1;
                        seen_tiles++;
                        board[px][0]++;
                        board[0][m_right]++;
                        py = m_right; 
                        break;
                    } else {
                        m_right = m_right - 1;
                    }
                }
                cout << px << " " << m_right << "\n";
                h = 'L';
            }
        }



        n_high = 1;
        n_low = n;
        while( board[0][py] < n  ) {
            if(v == 'B') {
                while(true) {
                    if(board[n_low][py] == 0) {
                        board[n_low][py] = 1;
                        seen_tiles++;
                        board[0][py]++;
                        board[n_low][0]++;
                        px = n_low;
                        break;
                    } else {
                        n_low = n_low - 1;
                    }
                }
                cout << n_low << " " << py << "\n";
                v = 'H';
            } else {
                while(true) {
                    if(board[n_high][py] == 0) {
                        board[n_high][py] = 1;
                        seen_tiles++;
                        board[0][py]++;
                        board[n_high][0]++;
                        px = n_high;
                        break;
                    } else {
                        n_high = n_high + 1;
                    }
                }
                cout << n_high << " " << py << "\n";
                v = 'B';
            }
        }

    }
}