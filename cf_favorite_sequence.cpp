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

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int N;
        cin >> N;

        vector<int> b_vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> b_vec[i];
        }

        vector<int> a_vec(N, 0);
        int index = 0;
        for(int i = 0; i <= ceil(double(N)/2.0)-1; i++) {
            // cout << "i:" << i << " index: " << index << endl;
            a_vec[index] = b_vec[i];
            index += 2;
        }

        if (N % 2 == 0) {
            index = N - 1;
        } else {
            index = N - 2;
        }

        for(int i = ceil(double(N)/2.0); i < N; i++) {
            // cout << "i:" << i << " index: " << index << endl;
            a_vec[index] = b_vec[i];
            index -= 2;
        }

        print_vector(a_vec);

    }

}