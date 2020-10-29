#include <bits/stdc++.h> 

using namespace std;
typedef unsigned long long int ulli;

template<typename T> void print_vector(vector<T> &v){

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}


int main() {

    const unsigned long long MOD7 = 1000000000+7;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {

        int N;
        cin >> N;
        vector<pair<int, int>> odd;
        vector<pair<int, int>> even;

        int MAX_CAPACITY = 2*N;

        odd.reserve(MAX_CAPACITY);
        even.reserve(MAX_CAPACITY);

        for(int n = 0; n < 2*N; n++) {
            int a;
            cin >> a;

            if(a % 2 == 0) {
                even.push_back(make_pair(n + 1, a));
            } else {
                odd.push_back(make_pair(n + 1, a));
            }
        }

        int index = 0;
        for(int i = 1; i < odd.size(); i = i + 2) {
            // cout << "index: " << index << "\n";
            if(index <= N - 2) {
                cout << odd[i - 1].first << " " << odd[i].first << "\n";
                index += 1;
            } else {
                break;
            }
        }

        for(int i = 1; i < even.size(); i = i + 2) {
            // cout << "index: " << index << "\n";
            if(index <= N - 2) {
                cout << even[i - 1].first << " " << even[i].first << "\n";
                index += 1;
            } else {
                break;
            }
        }


    }

}