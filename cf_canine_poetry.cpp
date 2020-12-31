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
 
        string s;
        cin >> s;

        int res = 0;
        vector<int> marker(s.size(), 0);
        for(int i = 1; i < s.size(); i++) {

            if(i - 1 >= 0) {
                if(s[i] == s[i-1]) {
                    if(marker[i] == 0 && marker[i-1] == 0) {
                        marker[i] = 1;
                        res++;
                        continue;
                    }
                }
            }

            if(i - 2 >= 0) {
                if(s[i-2] == s[i]){
                    if(marker[i] == 0 && marker[i-2] == 0) {
                        marker[i] = 1;
                        res++;
                        continue;
                    }
                }
            }
        }

        cout << res << "\n";
    }


}