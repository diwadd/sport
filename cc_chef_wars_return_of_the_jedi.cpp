#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int H, P;
        cin >> H >> P;

        bool h_zero = false;
        bool p_zero = false;
        while(true) {
            H = H - P;
            if(H <= 0){
                h_zero = true;
                break;
            }
            
            P = floor(P / 2);
            if(P <= 0) {
                p_zero = true;
                break;
            }
        }

        if(p_zero == true) {
            cout << "0\n"; 
        } else if(h_zero == true) {
            cout << "1\n";
        }


    }
}