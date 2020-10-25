#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

template<typename T> void print_vector(vector<T> &vec) {

    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

template<typename T> void print_matrix(vector<vector<T>> &mat) {
    for(int i = 0; i < mat.size(); i++) {
        cout << i << ": ";
        print_vector(mat[i]);
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    int n_letters = 20;
    vector<vector<int>> graph(n_letters, vector<int>());
    for(int t = 1; t <= T; t++) {

        int N;
        cin >> N;

        const int MAX_W_ELEMENT = 50;
        vector<int> w_vec(N, 0);
        vector<int> freq(MAX_W_ELEMENT + 1, 0);

        int min_ele = numeric_limits<int>::max();
        int max_ele = numeric_limits<int>::min();
        for(int i = 0; i < N; i++) {
            cin >> w_vec[i];
            freq[w_vec[i]]++;

            if(w_vec[i] <= min_ele) {
                min_ele = w_vec[i];
            }
            if(w_vec[i] >= max_ele) {
                max_ele = w_vec[i]; 
            }
        }

        int res = 0;
        for(int s = 2 * min_ele; s <= 2 * max_ele; s++) {

            int val_for_s = 0;
            if(s % 2 == 0) {
                for(int i = 0; i < s / 2; i++) {
                    int j = s - i;
                    if(j > N)
                        continue;
                    val_for_s += min(freq[i], freq[j]);
                }
                val_for_s += freq[s / 2] / 2;     
            } else {
                for(int i = 0; i <= s / 2; i++) {
                    int j = s - i;
                    if(j > N)
                        continue;
                    val_for_s += min(freq[i], freq[j]);
                }
            }

            if(val_for_s > res) {
                res = val_for_s;
            }
        }
        cout << res << "\n";
    }
}