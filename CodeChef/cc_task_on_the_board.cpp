#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;


void print_vector(vector<int> &vec) {

    for(auto v : vec) {
        cout << v << " ";
    }
    cout << "\n";
}

int main() {

    const unsigned long long MOD7 = 1000000000+7;

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int Q;
    cin >> Q;

    for(int q = 0; q < Q; q++) {

        string s;
        cin >> s;

        int M;
        cin >> M;

        vector<int> b_vec(M, 0);
        for(int i = 0; i < M; i++) {
            int b;
            cin >> b;
            b_vec[i] = b;
        }

        map<char, int> s_freq;
        for(int i = 0; i < s.length(); i++) {
            s_freq[s[i]]++;
        }

        int string_index = 0;
        int seen_zeros = 0;

        string t(M, '-');
        auto it = s_freq.rbegin();
        while(seen_zeros < b_vec.size()) {

            vector<int> positions;
            for(int i = M - 1; i >= 0; i--) {
 
                if(b_vec[i] != 0) {
                    continue;
                } else {

                    seen_zeros++;

                    string_index++;
                    positions.push_back(i);
                    b_vec[i] = -1;

                }
            
            }

            while(it->second < positions.size()) {
                it++;
            }

            for(int i = 0; i < positions.size(); i++) {
                t[positions[i]] = it->first;
            }
            it++;

            for(int i = 0; i < positions.size(); i++) {

                int p = positions[i];
                for(int j = M - 1; j >= 0; j--) {

                    b_vec[j] = b_vec[j] - abs(p - j);
                }
            }
        }
        cout << t << "\n";
    }
}