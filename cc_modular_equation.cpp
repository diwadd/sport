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


template<typename T> unsigned int binary_search(vector<T> &v, T target) {

    unsigned int left = 0;
    unsigned int right = v.size() - 1;
    while(left < right) {
        unsigned int mid = left + (right - left) / 2;
        if(v[mid] == target) {
            return mid;
        } else if(v[mid] < target) {
            left = mid + 1;
        } else if(v[mid] > target) {
            right = mid - 1;
        }
    }
    return left;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    int MAX_M = 500000 + 7;
    int INIT_SPACE = 10;
    vector<vector<int>> factors(MAX_M, vector<int>(1, 1));
    for(int i = 0; i < factors.size(); i++) {
        factors[i].reserve(INIT_SPACE);
    }

    for(int m = 2; m < MAX_M; m++) {

        int j = m;
        while(j <= MAX_M) {
            factors[j].push_back(m);
            j += m;
        }
    }

    for(int t = 0; t < T; t++) {
 
        int N, M;
        cin >> N >> M;

        ulli res = 0;
        for(int b = 2; b <= N; b++) {
            unsigned int y = M - M % b;

            if(b <= M) {
                unsigned int index = binary_search(factors[y], b);
                res += index;
            } else {
                res += (b - 1);
            }
        }

        cout << res << "\n";
    }
}