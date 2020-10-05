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
 
        lli N;
        cin >> N;

        lli res = 0;
        lli turn = 1;

        while(N > 0) {
            // int pN = N;
            // cout << turn << " ";
            if(turn == 1) {
                if(N % 4 == 0 && N > 8) {
                    res++;
                    N = N - 1;
                } else if(N % 2 == 0) {
                    res += N / 2;
                    N = N / 2;
                } else {
                    res++;
                    N = N - 1;
                }
                turn = 2;
            } else if (turn == 2) {
                if(N % 4 == 0 && N > 8) {
                    N = N - 1;
                } else if(N % 2 == 0) {
                    N = N / 2;
                } else {
                    N = N - 1;
                }
                turn = 1;   
            }
            // cout << pN << " -> " << N << " res: " << res << "\n";
        }

        // if(turn == 1) {
        //     res++;
        // }


        cout << res << "\n";
    }


}