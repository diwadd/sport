#include <bits/stdc++.h> 
 
using namespace std;
typedef long long int lli;
 
template<typename T> void print_vector(vector<T> &vec) {
 
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}
 
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for(int t = 1; t <= T; t++) {
 
        int N;
        cin >> N;
        vector<int> a_vec(N, 0);
 
        for(int i = 0; i < N; i++) {
            int ai;
            cin >> ai;
            a_vec[i] = ai;
        }
 
        vector<string> s_vec(N+1, string());
 
        int MAX_CHARS = 100;
        char ch = 'a';
        string ts(MAX_CHARS, ch);
        s_vec[0] = ts;

        for(int i = 0; i < N; i++) {
 
            s_vec[i+1] = s_vec[i];

            int ai = a_vec[i];

            if(s_vec[i+1][ai] == 'a') {
                ch = 'z';
            } else {
                ch = 'a';
            }

            for(int j = ai; j < MAX_CHARS; j++) {
                s_vec[i+1][j] = ch;
            }

        }
 
        for(int i = 0; i < N+1; i++) {
            cout << s_vec[i] << "\n";
        }
 
    }
}