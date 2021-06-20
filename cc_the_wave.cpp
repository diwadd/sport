#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<lli> a_vec(N, 0);

    for(auto& a : a_vec){
        cin >> a;
    }

    sort(a_vec.begin(), a_vec.end());

    for(int q = 0; q < Q; q++) {
        int x;
        cin >> x;

        auto it = lower_bound(a_vec.begin(), a_vec.end(), x);

        int index = it - a_vec.begin();

        if( x - (*it) == 0) {
            cout << "0\n";
        } else if(index % 2 != 0) {
            cout << "NEGATIVE\n";
        } else {
            cout << "POSITIVE\n";
        }

    }

}