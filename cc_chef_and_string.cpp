#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        string s;
        cin >> s;

        int res = 0;
        int N = s.length();

        vector<int> mask(N, 0);

        for(int i = 1; i < s.length(); i++) {
            if(s[i] == 'x' && mask[i] != 1){
                if(s[i-1] == 'y' && mask[i-1] != 1) {
                    res++;
                    mask[i-1] = 1;
                    mask[i] = 1;
                    continue;
                } else if (s[i+1] == 'y' && mask[i+1] != 1) {
                    res++;
                    mask[i+1] = 1;
                    mask[i] = 1;
                    continue;
                }

            } else if (s[i] == 'y' && mask[i] != 1) {
                if(s[i-1] == 'x' && mask[i-1] != 1) {
                    res++;
                    mask[i-1] = 1;
                    mask[i] = 1;
                    continue;
                } else if (s[i+1] == 'x' && mask[i+1] != 1) {
                    res++;
                    mask[i+1] = 1;
                    mask[i] = 1;
                    continue;
                }

            }

        }

        cout << res << "\n";

    }
}