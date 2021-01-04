#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int x;
        cin >> x;

        int sum = 0;
        string s = "";
        for(int i = 9; i >= 1; i--) {

            bool is_ok = false;
            for(int j = 1; j <= i; j++) {

                if(sum + j == x) {
                    s = to_string(j) + s;
                    sum = sum + j;
                    is_ok = true;
                    break;
                }

            }
            if(is_ok == false) {
                sum = sum + i;
                s = to_string(i) + s;
            } else {
                break;
            }
        }
        
        if(sum == x)
            cout << s << "\n";
        else
            cout << "-1\n";
    }

}