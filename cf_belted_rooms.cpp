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
 
        int N;
        cin >> N;

        string s;
        cin >> s;

        int ac = 0;
        int co = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '>')
                co++;
            else if(s[i] == '<')
                ac++;
        }

        if(ac == 0 || co == 0) {
            cout << N << "\n";
            continue;
        }

        vector<int> rooms(N, 0);
        for(int i = 0; i < s.size(); i++) {
            // cout << "i = " << i << "\n";
            if(s[i] == '-') {
                if(i + 1 < N) {
                    rooms[i+1] = 1;
                } else if (i + 1 == N) {
                    rooms[0] = 1;
                }
                rooms[i] = 1;
            }
        }

        // print_vector(rooms);

        int res = 0;
        for(int i = 0; i < N; i++) {
            if(rooms[i] == 1)
                res++;
        }

        cout << res << "\n";
    }


}