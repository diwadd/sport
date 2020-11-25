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

        vector<int> a_vec(N, 0);
        for(int i = 0; i < N; i++) {
            cin >> a_vec[i];
        }

        auto last = unique(a_vec.begin(), a_vec.end());
        a_vec.erase(last, a_vec.end());
        int m = a_vec.size(); 
        map<int, int> freq;

        for(int i = 0; i < m; i++) {
            freq[a_vec[i]]++;
        }

        if(freq.size() == 1){
            cout << "0\n";
            continue;
        }

        int res = numeric_limits<int>::max();
        for(auto it = freq.begin(); it != freq.end(); it++) {
            int local_res = it->second + 1;
            if(a_vec[0] == it->first) {
                local_res--; 
            }
            if(a_vec[m-1] == it->first) {
                local_res--; 
            }
            if(local_res < res) {
                res = local_res;
            }
        }

        cout << res << "\n";
    }
}