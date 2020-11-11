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

        vector<int> av(N, 0);
        vector<int> bv(N, 0);

        for(int i = 0; i < N; i++)
            cin >> av[i];

        for(int i = 0; i < N; i++)
            cin >> bv[i];

        vector<pair<int,int>> abv(N, pair<int,int>(0,0));
        for(int i = 0; i < N; i++) {
            abv[i].first = av[i];
            abv[i].second = bv[i];
        }

        sort(abv.begin(), abv.end());

        vector<ulli> suffix(N+1, 0);
        suffix[suffix.size()-2] = abv[suffix.size()-2].second;
        for(int i = suffix.size()-3; i >= 0; i--) {
            suffix[i] = suffix[i+1] + ulli(abv[i].second);
        }

        // print_vector(suffix);

        ulli total_time = ulli(suffix[0]);
        for(int i = 0; i < N; i++) {
            ulli new_total_time = max(ulli(abv[i].first), ulli(suffix[i+1]));
            total_time = min(total_time, new_total_time);
        }

        cout << total_time << "\n";
    }
}