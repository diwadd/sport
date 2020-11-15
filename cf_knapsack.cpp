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
 
        ulli N, W;
        cin >> N >> W;

        vector<pair<ulli,ulli>> w_vec(N, pair<ulli,ulli>(0,0));
        bool is_w_2 = false;
        ulli target = -1;
        ulli target_j = -1;
        for(int n = 0; n < N; n++) {
            int w_i;
            cin >> w_i;
            w_vec[n] = make_pair(w_i, n+1);
        }


        sort(w_vec.rbegin(), w_vec.rend());

        vector<ulli> items;
        items.reserve(N);
        ulli C = 0;
        for(int n = 0; n < N; n++) {
            if (C + w_vec[n].first <= W) {

                C = C + w_vec[n].first;
                items.push_back(w_vec[n].second);
            }
            if(C >= ceil(double(W)/double(2.0)))
                break;
        }

        if(items.size() == 0 || C < ceil(double(W)/double(2.0))){
            cout << "-1\n";
        } else {
            cout << items.size() << "\n";
            print_vector(items);
        }

    }


}