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
 
 
        string s = to_string(N);
        int d = s[0] - '0';
        int m = s.size();
        int delta = 0;
 
        if(m == 1)
            delta = 1;
        else if (m == 2)
            delta = 3;
        else if (m == 3)
            delta = 6;
        else if (m == 4)
            delta = 10;
 
        int res = (d - 1) * 10 + delta;
 
        cout << res << "\n";
 
 
    }
 
 
}
