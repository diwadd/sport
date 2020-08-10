#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        lli N;
        cin >> N;
        
        for(int i = 1; i <= N; i++){
            if (i == N)
                cout << i << "\n";
            else
                cout << i << " ";
        }


    }
}