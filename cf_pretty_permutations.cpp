#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

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

void flip_neighbours(vector<int> & vec, int upto) {

    for(int i = 0; i < upto; i = i + 2) {
        swap(vec[i], vec[i+1]);
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

        vector<int> perm(N, 0);

        for(int i = 0; i < N; i++) {
            perm[i] = i + 1;
        }

        if(N % 2 == 0) {
            int upto = perm.size();
            flip_neighbours(perm, upto);
            print_vector(perm);
        } else {
            int upto = perm.size();
            flip_neighbours(perm, upto-1);
            swap(perm[upto-1], perm[upto-2]);
            print_vector(perm);
        }
    }
}
