#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int N;
        cin >> N;

        int MAX_LETTERS = 26;
        vector<string> funny_words(N, "");
        map<string, int> word_endings_mapping;
        vector<string> word_endings_vec;
        word_endings_vec.reserve(N);

        unordered_set<string> words_lookup;
        words_lookup.reserve(2*N);

        int index = 0;
        for(int i = 0; i < N; i++) {
            string s;
            cin >> s;
            funny_words[i] = s;
            words_lookup.insert(s);

            string ending  = string(s.begin()+1, s.end());
            if(word_endings_mapping.find(ending) != word_endings_mapping.end()) {
                continue;
            } else {
                word_endings_mapping[ending] = index;
                word_endings_vec.push_back(ending);
                index++;
            }
        }

        vector<vector<int>> word_exists(MAX_LETTERS, vector<int>(N));
        for(int i = 0; i < MAX_LETTERS; i++) {
            for(int j = 0; j < word_endings_vec.size(); j++) {

                string candidate = char('a' + i) + word_endings_vec[j];
                if(words_lookup.find(candidate) != words_lookup.end()) {
                    word_exists[i][j] = 1;
                } else {
                    word_exists[i][j] = 0;
                }
            }
        }

        int res = 0;
        for(int i = 0; i < MAX_LETTERS; i++) {
            for(int j = 0; j < MAX_LETTERS; j++) {
                int c1 = 0;
                int c2 = 0;
                for(int k = 0; k < word_endings_vec.size(); k++) {

                    if(word_exists[i][k] == 0 && word_exists[j][k] == 1) {
                        c1++;
                    }                    
                    if(word_exists[j][k] == 0 && word_exists[i][k] == 1) {
                        c2++;
                    }

                }
                res += c1*c2;
            }
        }

        cout << res << "\n";
    }
}
    