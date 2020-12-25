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

 
    int N;
    cin >> N;

    if(N % 2 == 0){
        cout << (N/2 + 1)*(N/2 + 1) << "\n";
    } else {
        int m = ceil(double(N)/2);
        int res = 0;
        for(int i = 1; i <= m; i++) {
            res = res + 4*i;
        }
        cout << res << "\n";
    }

}