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

        bool is_ok = false;
        for(char c = 'a'; c <= 'z'; c++) {
            string sub({c});
            if( s.find(sub) == string::npos ) {
                cout << sub << "\n";
                is_ok = true;
                break;
            }
        }

        if(is_ok)
            continue;

        for(char c1 = 'a'; c1 <= 'z'; c1++) {
            for(char c2 = 'a'; c2 <= 'z'; c2++) {
                string sub({c1, c2});
                if( s.find(sub) == string::npos ) {
                    cout << sub << "\n";
                    is_ok = true;
                    break;
                }
            }
            if(is_ok)
                break;
        }

        if(is_ok)
            continue;

        for(char c1 = 'a'; c1 <= 'z'; c1++) {
            for(char c2 = 'a'; c2 <= 'z'; c2++) {
                for(char c3 = 'a'; c3 <= 'z'; c3++) {
                    string sub({c1, c2, c3});
                    if( s.find(sub) == string::npos ) {
                        cout << sub << "\n";
                        is_ok = true;
                        break;
                    }
                }
                if(is_ok)
                    break;
            }
            if(is_ok)
                break;
        }


    }


}