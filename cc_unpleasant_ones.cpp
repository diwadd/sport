#include <bits/stdc++.h> 

using namespace std;

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

        vector<int> a_vec(N, 0);
        for(auto &a : a_vec) {
            cin >> a;
        }

        vector<int> back_zeros;
        back_zeros.reserve(N);

        vector<int> back_ones;
        back_zeros.reserve(N);

        for(int i = 0; i < N; i++) {
            int a = a_vec[i];
            if(a & 1 == 1) {
                back_ones.push_back(a);
            } else {
                back_zeros.push_back(a);
            }
        }

        back_zeros.insert( back_zeros.end(), back_ones.begin(), back_ones.end() );

        print_vector(back_zeros);
    }
}