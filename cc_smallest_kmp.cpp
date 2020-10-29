#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        string S, P;
        cin >> S >> P;

        const int N_LETTERS = 26;
        vector<int> freq(N_LETTERS, 0);

        for(int i = 0; i < P.size(); i++) {
            freq[P[i] - 'a']++;
        }

        bool prepend_to_p0 = false;
        for(int i = 1; i < P.size(); i++) {
            if(P[i] == P[i-1])
                continue;

            if(P[i] < P[i-1]) {
                prepend_to_p0 = true;
            }
            break;
        }

        vector<string> letters_words_no(N_LETTERS, string());
        vector<string> letters_words_re(N_LETTERS, string());
        const int MAX_LETTERS_WORDS = 200000 + 7;
        letters_words_no.reserve(MAX_LETTERS_WORDS);
        letters_words_re.reserve(MAX_LETTERS_WORDS);

        for(int i = 0; i < S.size(); i++) {
            if(freq[S[i] - 'a'] > 0) {
                freq[S[i] - 'a']--;
            } else {
                if(prepend_to_p0 == true && S[i] == P[0]) {
                    P += S[i];
                } else {
                    letters_words_no[S[i] - 'a'] += S[i];
                    letters_words_re[S[i] - 'a'] += S[i];
                }
            }
        }

        letters_words_no.push_back(P);
        letters_words_re.push_back(P);

        sort(letters_words_no.begin(), letters_words_no.end());
        sort(letters_words_re.rbegin(), letters_words_re.rend());

        string no = "";
        for(auto s : letters_words_no)
            no += s;

        string re = "";
        for(auto s : letters_words_re)
            re += s;

        if(no < re)
            cout << no << "\n";
        else
            cout << re << "\n";
    }
}