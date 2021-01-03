#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
 
    for(int t = 0; t < T; t++) {
 
        int a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;

        vector<int> av = {a1, a2, a3, a4};
        sort(av.begin(), av.end());

        cout << av[1]*av[2] << "\n";

    }
}