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
    for(int i = 1; i < n; i++) {
        if(i == n - 1)
            cout << vec[i];
        else
            cout << vec[i] << " ";
    }
    cout << "\n";
}

template<typename T> void print_map(map<T, T> &m) {
    for(const auto & e : m) {
        cout << e.first << " " << e.second << endl;
    }
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

        int MAX_A_VAL = 10;
        // vector<pair<int,int>> freq(MAX_A_VAL+1, pair<int,int>(0,0));
        vector<int> freq(MAX_A_VAL+1, 0);

        for(int n = 0; n < N; n++) {
            int a;
            cin >> a;
            freq[a]++;
        }

        // sort(freq.begin(), freq.end(), comp);

        map<int,int> fof;
        for(int i = 1; i < MAX_A_VAL+1; i++) {
            fof[freq[i]]++;
        }

        // print_map(fof);

        int max_freq = numeric_limits<int>::min();
        for(auto it = fof.begin(); it != fof.end(); it++) {
            if(it->first == 0 || it->second == 0)
                continue;
            
            if(it->second > max_freq) {
                // cout << "it->first: " << it->first << " it->second: " << it->second << "\n";
                max_freq = it->second;
            }
        }

        int min_max_num = numeric_limits<int>::max();
        for(auto it = fof.begin(); it != fof.end(); it++) {
            if(it->first == 0 || it->second == 0)
                continue;
            
            if(it->second == max_freq) {
                // cout << "-> it->first: " << it->first << " it->second: " << it->second << " min_max_num: " << min_max_num << "\n";
                if(it->first < min_max_num) {
                    min_max_num = it->first;
                }
            }
        }

        cout << min_max_num << "\n";

    }


}