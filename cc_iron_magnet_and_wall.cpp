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

template<typename T> void print_container(T &vec) {

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
 
        int N, K;
        cin >> N >> K;

        string s;
        cin >> s;

        int n_sheets = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ':')
                n_sheets++;
        }

        vector<char> chain_rep;
        chain_rep.reserve(N+n_sheets+1);
        
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == ':') {
                chain_rep.push_back('_');
                chain_rep.push_back('_');
            } else {
                chain_rep.push_back(s[i]);
            }
        }

        // print_container(chain_rep);
        deque<int> seen_irons;
        deque<int> seen_magnets;

        int res = 0;
        for(int i = 0; i < chain_rep.size(); i++) {

            if(chain_rep[i] == '_') {
                continue;
            } else if(chain_rep[i] == 'X') {
                seen_irons.clear();
                seen_magnets.clear();
                continue;
            } else if (chain_rep[i] == 'I') {

                // cout << "Found I at " << i << endl;
                bool paired_magnet = false;
                while (seen_magnets.empty() == false) {
                    int magnet_index = seen_magnets.front();
                    // cout << "Magnet in Q with index: " << magnet_index << endl;
                    int c = K + 1 - abs(i - magnet_index);
                    // cout << "c = " << c << endl;
                    if(c > 0) {
                        res++;
                        seen_magnets.pop_front();
                        paired_magnet = true;
                        break;
                    } else {
                        seen_magnets.pop_front();
                    }
                }
                if(paired_magnet == false) {
                    seen_irons.push_back(i);
                }

            } else if (chain_rep[i] == 'M') {

                // cout << "Found M at " << i << endl;
                bool paired_iron = false;
                while (seen_irons.empty() == false) {
                    int iron_index = seen_irons.front();
                    // cout << "Iron in Q with index: " << iron_index << endl;
                    int c = K + 1 - abs(i - iron_index);
                    // cout << "c = " << c << endl;
                    if(c > 0) {
                        res++;
                        seen_irons.pop_front();
                        paired_iron = true;
                        break;
                    } else {
                        seen_irons.pop_front();
                    }
                }
                if(paired_iron == false) {
                    seen_magnets.push_back(i);
                }

            }

        }

        cout << res << "\n";

    }


}