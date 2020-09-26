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

    vector<int> a_vec(N, 0);
    for(int n = 0; n < N; n++)
        cin >> a_vec[n];

    sort(a_vec.begin(), a_vec.end());

    int index = 0;
    vector<int> r_vec(N, 0);
    for(int i = 1; i < N; i = i + 2)
        r_vec[i] = a_vec[index++];
    for(int i = 0; i < N; i = i + 2)
        r_vec[i] = a_vec[index++];


    int res = 0;
    for(int i = 1; i < N-1; i++) {
        if(r_vec[i] < r_vec[i-1] && r_vec[i] < r_vec[i+1])
            res++;
    }

    cout << res << "\n";
    print_vector(r_vec);

}