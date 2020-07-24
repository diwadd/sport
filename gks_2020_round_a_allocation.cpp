#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

template<typename T> void print_vector(vector<T> &vec) {

    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++) {

        int N, B;
        cin >> N >> B;
        vector<int> a_vec(N, 0);

        for(int i = 0; i < N; i++) {
            int ai;
            cin >> ai;
            a_vec[i] = ai;
        }

        sort(a_vec.begin(), a_vec.end());
        // print_vector(a_vec);

        int n_houses = 0;
        int cost = 0;
        for(int i = 0; i < N; i++) {
            if(cost + a_vec[i] <= B) {
                cost += a_vec[i];
                n_houses++;
            }
        }

        cout << "Case #" << t << ": " << n_houses << "\n";
    }
}