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

        lli N, X;
        cin >> N >> X;

        int f = 1;
        int e = 2;
        int floor_number = 1;
        while(true) {
            if(N >= f && N <= e) {
                break;
            }
            f = e + 1;
            e = (floor_number * X + 2);
            floor_number++;
            // cout << "f: " << f << " e: " << e << " N: " << N << " floor_number: " << floor_number << "\n";
        }

        cout << floor_number << "\n";

    }

}