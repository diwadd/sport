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

        string s;
        cin >> s;

        int c = 0;
        for(int i = 0; i < N; i++) {
            if(s[i] - '0' == 1)
                c++;
        }

        int res = numeric_limits<int>::max();
        for(int d = 1; d <= N; d++) {

            if(N % d == 0) {

                for(int shift = 0; shift < d; shift++) {

                    int x = 0;
                    for(int p = shift; p < N; p += d) {
                        
                        if(s[p] - '0' == 1){
                            x++;
                        }

                    }

                    res = min(res, N/d + c - 2 * x);
                }
            }
        }

        cout << res << "\n";
    }
}