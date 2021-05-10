#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int N;
        cin >> N;

        string s;
        cin >> s;

        vector<int> vec;
        vec.reserve(N);

        int start = -1;
        for(int i = 0; i < N; i++) {
            if(s[i] == '*') {
                start = i;
                break;
            }
        }

        int stop = -1;
        for(int i = N-1; i >= 0; i--) {
            if(s[i] == '*') {
                stop = i;
                break;
            }
        }

        for(int i = start; i <= stop; i++) {
            if(s[i] == '*')
                vec.push_back(1);
            else
                vec.push_back(0);
        }

        vector<int> left(vec.size(), 0);
        vector<int> right(vec.size(), 0);

        left[0] = 1;
        for(int i = 1; i < vec.size(); i++) {
            if(vec[i] == 1) {
                left[i] = left[i-1] + 1;
            } else {
                left[i] = left[i-1];
            }
        }

        right[right.size()-1] = 1;
        for(int i = vec.size()-2; i >= 0; i--) {
            if(vec[i] == 1) {
                right[i] = right[i+1] + 1;
            } else {
                right[i] = right[i+1];
            }
        }

        ulli res = 0;
        for(int i = vec.size()-2; i >= 0; i--) {
            if(vec[i] == 1) {
                continue;
            } else {
                res += min(ulli(left[i]), ulli(right[i]));
            }
        }

        cout << res << "\n";

    }


}