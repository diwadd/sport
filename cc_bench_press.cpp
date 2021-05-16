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
 
        int N, W, Wr;
        cin >> N >> W >> Wr;

        map<ulli, ulli> freq;
        vector<ulli> w_vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> w_vec[i];
            freq[w_vec[i]]++;
        }

        ulli res = 0;
        for(auto it = freq.begin(); it != freq.end(); it++) {
            if( it->second % 2 != 0) {
                (it->second)--;
            }
            res += (it->first)*(it->second);
        }

        // cout << "res + Wr: " << res + Wr << endl;
        if(res + Wr >= W) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }


    }


}