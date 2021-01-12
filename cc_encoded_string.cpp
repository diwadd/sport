#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

char get_letter(string &s, int &start, int &&stop) {

    char sixteen_letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};

    int f = 0;
    int e = 15;
    for(int i = start; i < stop; i++) {
        int d = (e - f) / 2;
        // cout << "f: " << f << " e: " << e << " d: " << d << endl;

        if(s[i] == '0') {
            f = f;
            e = f + d;
        } else {
            f = f + d + 1;
            e = e;
        }
    }
    // cout << "f: " << f << " e: " << e << endl;
    return sixteen_letters[f];
}


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

        string res = "";
        for(int i = 0; i < s.size(); i = i + 4) {
            // cout << i << " " << i + 4 << "\n";
            res += get_letter(s, i, i+4);
        }

        cout << res << "\n";

    }


}